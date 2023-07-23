#pragma once

#include "Population.hpp"
#include "RuntimeStatistics.hpp"
#include "Worker.hpp"
#include "Parameters.hpp"
#include "Warehouse.hpp"
#include "Delivery.hpp"
#include "Shipment.hpp"

#include <array>

class Simulator {
    Warehouse& warehouse;
    std::array<Worker, Parameters::N_WORKERS> workers;
    Shipment currShipment; // current order

    double calculateFitness(const RuntimeStatistics&) const;
    double boxWorkerDist(Worker&, Box&) const;
    std::array<Worker, Parameters::N_WORKERS> createWorkers(const Specimen&) const;
    void receiveDelivery();
    void sendShipment();
    std::array<int, Parameters::N_COLORS> numberOfBoxesOfGivenColor(const std::vector<Box>&) const;
    std::array<bool, Parameters::N_COLORS> checkShipmentStatus() const;
    const Worker& findNearestWorker(const Worker&) const;
    void updateNearestBoxesData(const Worker&, WorkerInput&) const;
    WorkerInput generateWorkerInputData(const Worker&) const;
    void makeAction(Worker&, const WorkerOutput&);
public:
    Simulator(Warehouse& warehouse, Specimen& specimen);
    double simulate();
};