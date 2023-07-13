#pragma once

#include "Box.hpp"

#include <vector>

class Warehouse {
    std::vector<Box> boxes;
    double minX;
    double minY;
    double maxX;
    double maxY;
    double deliveryZoneHeight;
    double shipmentZoneHeight;
public:
    Warehouse();
    double getMinX() const { return minX; };
    double getMinY() const { return minY; };
    double getMaxX() const { return maxX; };
    double getMaxY() const { return maxY; };
    double getdeliveryZoneHeight() const { return deliveryZoneHeight; };
    double getshipmentZoneHeight() const { return shipmentZoneHeight; };
    void addBox(const Box& box) { boxes.push_back(box); };
    void deleteBox(const Box&);
    bool isDeliveryZoneEmpty();
    std::vector<Box>& getBoxes() { return boxes; };
};