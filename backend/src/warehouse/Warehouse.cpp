#include "Warehouse.hpp"
#include "SimulatorParameters.hpp"
#include "Parameters.hpp"

#include <algorithm>

using namespace std;

Warehouse::Warehouse() {
    minX = SimulatorParameters::minX;
    minY = SimulatorParameters::minY;
    maxX = SimulatorParameters::maxX;
    maxY = SimulatorParameters::maxY;
    deliveryZoneHeight = SimulatorParameters::deliveryZoneHeight;
    shipmentZoneHeight = SimulatorParameters::shipmentZoneHeight;
}

void Warehouse::deleteBox(const Box& box) {
    auto boxIter = find(boxes.begin(), boxes.end(), box);
    if (boxIter != boxes.end()) {
        boxes.erase(boxIter);
    }
}

std::vector<Box> Warehouse::getBoxesInDeliveryZone(){
    vector<Box> boxesDelivery;
    for(auto box : boxes){
        if(box.isInDeliveryZone()){
            boxesDelivery.push_back(box);
        }
    }
    return boxesDelivery;
}

std::vector<Box> Warehouse::getBoxesInShipmentZone(){
    vector<Box> boxesShipment;
    for(auto box : boxes){
        if(box.isInShipmentZone()){
            boxesShipment.push_back(box);
        }
    }
    return boxesShipment;
}

bool Warehouse::isDeliveryZoneEmpty(){
    return (getBoxesInDeliveryZone().size() == 0);
}