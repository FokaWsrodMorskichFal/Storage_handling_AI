#include "Simulator.hpp"
#include "SimulatorParameters.hpp"
#include "Warehouse.hpp"
#include "RNG.hpp"
#include "Position.hpp"

#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using namespace Parameters;
using namespace SimulatorParameters;
using namespace WorkerGrabAction;

double boxWorkerDist(Worker& w, Box& b){
    return sqrt(pow(w.getX() - b.getX(), 2) + pow(w.getY() - b.getY(), 2));
}   

array<int, Parameters::N_COLORS> Simulator::numberOfBoxesOfGivenColor(const vector<Box>& boxes) const {
    array<int, Parameters::N_COLORS> numOfBoxesOfGivenColor = {0};
    for(const auto& box : boxes){
        numOfBoxesOfGivenColor[box.getColor()]++;
    }
    return numOfBoxesOfGivenColor;
}

void Simulator::receiveDelivery(){
    //vector<Box> curr_boxes = warehouse.getBoxes();
    //na podstawie boxów w Warehouse wybierany skład dostawy
    //wersja tmp
    for(int i=0;i<N_COLORS;i++){
        warehouse.addBox(Box(minX+(i+1)*(maxX-minX)/(N_COLORS + 1), maxY-(deliveryZoneHeight)/2, i));
    }
}

array<bool, Parameters::N_COLORS> Simulator::checkShipmentStatus() const{
    array<bool, Parameters::N_COLORS> colorsNeeded = {false};
    array<int, Parameters::N_COLORS> numOfBoxesOfGivenColorInShipmentZone = numberOfBoxesOfGivenColor(warehouse.getBoxesInShipmentZone());
    array<int, Parameters::N_COLORS> order = currShipment.getOrder();
    for(int i=0;i<Parameters::N_COLORS;i++){
        if(numOfBoxesOfGivenColorInShipmentZone[i]==order[i]){
            colorsNeeded[i] = true;
        }
    }
    return colorsNeeded;
} 

void Simulator::sendShipment(){
    std::vector<Box> boxesInShipmentZone = warehouse.getBoxesInShipmentZone();
    for(auto box : boxesInShipmentZone){
        warehouse.deleteBox(box);
    }
}

array<Worker, N_WORKERS> Simulator::createWorkers(const Specimen& specimen) const {
    array<Worker, N_WORKERS> workers;
    auto workersIter = workers.begin();
    for (const auto& neuralNetwork : specimen.getNNs()) {
        *workersIter = Worker(neuralNetwork);
        ++workersIter;
    }
    return workers;
}

Simulator::Simulator(Warehouse& warehouse, Specimen& specimen) : warehouse(warehouse) {
    workers = createWorkers(specimen);
}

const Worker& Simulator::findNearestWorker(const Worker& thisWorker) const {
    double minDistance = numeric_limits<double>::max();
    const Worker* nearestWorker = nullptr;
    for (auto& otherWorker : workers) {
        if (&otherWorker == &thisWorker) {
            continue;
        }
        double distance = thisWorker.distance(otherWorker);
        if (distance < minDistance) {
            nearestWorker = &otherWorker;
        }
    }
    return *nearestWorker;
}

array<bool, N_COLORS> getColorMaskOfHeldBoxByNN(const Worker& nearestWorker) {
    array<bool, N_COLORS> mask = {false};
    if (nearestWorker.doesHoldBox()) {
        mask[nearestWorker.getHeldBox().getColor()] = true;
    }
    return mask;
}

void Simulator::updateNearestBoxesData(const Worker& worker, WorkerInput& input) const {
    Position thisWorkerPos(worker.getX(), worker.getY());
    vector<Box> boxes = warehouse.getBoxes();
    array<vector<Box>, N_COLORS> sortedBoxesByColor;
    for (const auto& box : boxes) {
        if (!box.checkIfHeld()) {
            sortedBoxesByColor[box.getColor()].push_back(box);
        }
    }
    for (int color = 0; color < N_COLORS; ++color) {
        double minDistance = numeric_limits<double>::max();
        Position workerPos = Position(worker.getX(), worker.getY());
        Box* nearestBox = nullptr;
        for (auto& box : sortedBoxesByColor[color]) {
            double distance = workerPos.distance(Position(box.getX(), box.getY()));
            if (distance < minDistance) {
                nearestBox = &box;
            }
        }
        if (nearestBox == nullptr) {
            input.boxPositions[color] = { .0, .0 };
        } else {
            if (Position(nearestBox->getX(), nearestBox->getY()).distance(thisWorkerPos) <= grabRange) {
                input.boxInRange = true;
            }
            input.boxPositions[color] = { nearestBox->getX(), nearestBox->getY() };
        }
    }
}

WorkerInput Simulator::generateWorkerInputData(const Worker& worker) const {
    WorkerInput input;
    Worker nearestWorker = findNearestWorker(worker);
    input.xNN = nearestWorker.getX();
    input.yNN = nearestWorker.getY();
    input.smellNN = nearestWorker.getSmell();
    input.areaLoad = warehouse.isDeliveryZoneEmpty() ? -1 : 1;
    input.colorsNN = getColorMaskOfHeldBoxByNN(nearestWorker);
    input.neededBox = checkShipmentStatus();
    updateNearestBoxesData(worker, input);
    return input;
}

double Simulator::simulate() {
    const double dt = DELTA_T;
    const double maxSimulationTime = MAX_SIM_T;
    double simulationTime = .0;
    // Init Delivery
    receiveDelivery();
    for (; simulationTime < maxSimulationTime; simulationTime += dt) {
        for (Worker& worker : workers) {
            WorkerInput input = generateWorkerInputData(worker);
            WorkerOutput output = worker.decideAction(input);
            makeAction(worker, output);
        }
    }
    RuntimeStatistics runtimeStatistics;
    // TODO change fitness calculations
    double fitness = 0;
    for (int i = 0; i < N_WORKERS; ++i) {
        runtimeStatistics.meanSpeed[i] = workers[i].getTraveledDistance() / simulationTime;
        fitness += runtimeStatistics.meanSpeed[i];
    }
    return fitness;
}

void Simulator::makeAction(Worker& worker, const WorkerOutput& output) {
    if (output.grabAction == GRAB_ACTION) {
        Position thisWorkerPos(worker.getX(), worker.getY());
        Box* nearestBox = nullptr;
        double minDistance = numeric_limits<double>::max();
        for (Box& box : warehouse.getBoxes()) {
            double distance = thisWorkerPos.distance(Position(box.getX(), box.getY()));
            if (!box.checkIfHeld() && distance < minDistance) {
                nearestBox = &box;
            }
        }
        if (minDistance <= grabRange) {
            worker.holdBox(*nearestBox);
        }
    } else if (output.grabAction == DROP_ACTION) {
        worker.dropBox();
    } else {
        worker.moveBy(output.xVel, output.yVel);
    }
    worker.setSmell(output.smell);
}
