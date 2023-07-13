#include "Simulator.hpp"
#include "SimulatorParameters.hpp"
#include "Warehouse.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"
#include "Position.hpp"

#include <cmath>
#include <algorithm>

double BoxWorkerDist(Worker& w, Box& b){
    return sqrt(pow(w.getX() - b.getX(), 2) + pow(w.getY() - b.getY(), 2));
}   

void Simulator::simulate(Population& population) const {
    for(auto& specimen : population) {
        double dt = SimulatorParameters::DELTA_T;
        double max_T = SimulatorParameters::MAX_SIM_T;
        //inicjalizacja magazynu
        Warehouse W;
        //spawn workerów
        std::array<Worker, Parameters::N_WORKERS> workers;
        for(int i=0;i<Parameters::N_WORKERS;i++){
            workers = specimen.getWorkers();
            workers[i].reset();
        }
        //spawn n pudełek
        for(int i=0;i<Parameters::N_INIT_BOXES;i++){
            W.addBox(Box(RNG::uniformRandom(-1., 1.), RNG::uniformRandom(-1.+SimulatorParameters::shipmentZoneHeight, 1.-SimulatorParameters::deliveryZoneHeight), RNG::uniformRandom(0, Parameters::N_COLORS - 1)));
        }
        //obiekty do ewaluacji decyzji sieci
        std::array<WorkerInput, Parameters::N_WORKERS> inputArray;
        //przygotowanie pierwszych inputów
        for(int i=0;i<Parameters::N_WORKERS;i++){
            inputArray[i].xPos=workers[i].getX();
            inputArray[i].xPos=workers[i].getY();
            
            double min_dist=abs(SimulatorParameters::minX)+abs(SimulatorParameters::maxX)+abs(SimulatorParameters::minY)+abs(SimulatorParameters::maxY);
            int NN_index=-1;
            for(int j=0;j<Parameters::N_WORKERS;j++){    
                if(i==j){
                    continue;
                }
                double dist=workers[i].distance(workers[j]);
                if(dist<min_dist){
                    min_dist=dist;
                    NN_index=j;
                }
            }
            
            inputArray[i].xNN=workers[NN_index].getX();
            inputArray[i].yNN=workers[NN_index].getY();
            inputArray[i].smellNN=workers[NN_index].getSmell();
            inputArray[i].areaLoad= W.isDeliveryZoneEmpty() ? -1 : 1;
            
            std::array<bool, Parameters::N_COLORS> bool_col;
            inputArray[i].heldBox=bool_col; 
            if(workers[i].doesHoldBox()){
                int color = workers[i].getHeldBox().getColor();  
                inputArray[i].heldBox[color]=true;
            }

            inputArray[i].colorsNN=bool_col;
            if(workers[NN_index].doesHoldBox()){
                int color = workers[NN_index].getHeldBox().getColor();  
                inputArray[i].colorsNN[color]=true;
            }

            //potrzebny obiekt zlecenia i dostawy w Simulator.cpp
            inputArray[i].neededBox={};

            Position thisWorkerPos(workers[i].getX(), workers[i].getY());
            std::vector<Box> boxes = W.getBoxes();
            std::array<std::vector<Box>, Parameters::N_COLORS> sortedBoxesByColor;
            for (const auto& box : boxes) {
                sortedBoxesByColor[box.getColor()].push_back(box);
            }
            for (int color = 0; color < Parameters::N_COLORS; ++color) {
                auto minIter = std::min(sortedBoxesByColor[color].begin(), sortedBoxesByColor[color].end(), [thisWorkerPos](const Box& v1, const Box& v2) {
                    return Position(v1.getX(), v1.getY()).distance(thisWorkerPos) < 
                        Position(v2.getX(), v2.getY()).distance(thisWorkerPos);
                });
                inputArray[i].boxPositions[color] = { minIter.base()->getX(), minIter.base()->getY() };
            }

        }

        // ewaluacja akcji workerów

    }
}