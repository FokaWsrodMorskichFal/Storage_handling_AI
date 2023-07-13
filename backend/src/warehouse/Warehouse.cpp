#include "Warehouse.hpp"
#include "SimulatorParameters.hpp"

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

bool Warehouse::isDeliveryZoneEmpty(){
    bool flag=true;
    int i=0;
    while(flag){
        if(boxes[i].getY() >= (1-SimulatorParameters::deliveryZoneHeight)){
            flag=false;
        }
        i++;
    }
    return flag;
}