#ifndef BATTERYPACK_H
#define BATTERYPACK_H

#include "Battery.h"
#include <vector>

class BatteryPack : public Battery
{
public:
    enum ConnectionType {
        SERIES,
        PARALLEL
    };

    BatteryPack(ConnectionType t);

    void add(Battery* b);

    void use(double hours);
    void recharge(double hours);

    double getVoltage() const override;
    double getCapacity() const override;
    double getCharge() const override;

    const std::vector<Battery*>& getCells() const;
    bool isSeries() const;

private:
    ConnectionType type;
    std::vector<Battery*> cells;
};

#endif // BATTERYPACK_H
