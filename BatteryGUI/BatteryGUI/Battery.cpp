#include "Battery.h"


constexpr double DISCHARGE_RATE = 100.0;
constexpr double RECHARGE_RATE = 100.0;

Battery::Battery(double v, double c, double initial)
    : voltage(v), capacity(c), charge(initial)
{
    if (charge > capacity) charge = capacity;
    if (charge < 0) charge = 0;
}

void Battery::use(double hours) {
    charge -= hours * DISCHARGE_RATE;
    if (charge < 0) charge = 0;
}

void Battery::recharge(double hours) {
    charge += hours * RECHARGE_RATE;
    if (charge > capacity) charge = capacity;
}

double Battery::getVoltage() const {
    return voltage;
}

double Battery::getCapacity() const {
    return capacity;
}

double Battery::getCharge() const {
    return charge;
}

double Battery::getPercent() const {
    return (capacity > 0) ? (100.0 * charge / capacity) : 0.0;
}
