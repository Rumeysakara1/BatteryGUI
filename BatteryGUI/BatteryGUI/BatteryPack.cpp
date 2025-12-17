#include "BatteryPack.h"

BatteryPack::BatteryPack(ConnectionType t)
    : Battery(0, 0, 0), type(t) {}


const std::vector<Battery*>& BatteryPack::getCells() const {
    return cells;
}

bool BatteryPack::isSeries() const {
    return type == SERIES;
}

void BatteryPack::add(Battery* b) {
    cells.push_back(b);
}

void BatteryPack::use(double hours) {
    for (Battery* b : cells) {
        b->use(hours);
    }
}

void BatteryPack::recharge(double hours) {
    for (Battery* b : cells) {
        b->recharge(hours);
    }
}

double BatteryPack::getVoltage() const {
    if (cells.empty()) return 0.0;

    if (type == SERIES) {
        double sum = 0;
        for (auto b : cells) sum += b->getVoltage();
        return sum;
    } else { // PARALLEL
        return cells.empty() ? 0.0 : cells[0]->getVoltage();
    }
}

double BatteryPack::getCapacity() const {
    if (cells.empty()) return 0.0;

    if (type == SERIES) {
        double minCap = cells[0]->getCapacity();
        for (auto b : cells) {
            if (b->getCapacity() < minCap) minCap = b->getCapacity();
        }
        return minCap;
    } else { // PARALLEL
        double sum = 0;
        for (auto b : cells) sum += b->getCapacity();
        return sum;
    }
}

double BatteryPack::getCharge() const {
    if (cells.empty()) return 0.0;

    if (type == SERIES) {
        double minCharge = cells[0]->getCharge();
        for (auto b : cells) {
            if (b->getCharge() < minCharge) minCharge = b->getCharge();
        }
        return minCharge;
    } else { // PARALLEL
        double sum = 0;
        for (auto b : cells) sum += b->getCharge();
        return sum;
    }
}








