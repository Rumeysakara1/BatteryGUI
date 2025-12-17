#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>

/**
 * @brief Represents a single battery cell.
 */
class Battery {
protected:
    double voltage;   ///< Voltage in volts
    double capacity;  ///< Capacity in mAh
    double charge;    ///< Current charge in mAh

    static constexpr double DISCHARGE_RATE = 100; ///< Fixed discharge rate (mAh/hour)
    static constexpr double RECHARGE_RATE = 150;  ///< Fixed recharge rate (mAh/hour)

public:
    /**
     * @brief Construct a new Battery object.
     * @param v Voltage in volts.
     * @param c Capacity in mAh.
     * @param initial Initial charge in mAh.
     */
    Battery(double v, double c, double initial);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Battery() {}

    /**
     * @brief Decreases charge based on a fixed discharge rate.
     * @param hours Number of hours of usage.
     */
    virtual void use(double hours);

    /**
     * @brief Increases charge based on a fixed recharge rate.
     * @param hours Number of hours of charging.
     */
    virtual void recharge(double hours);

    /**
     * @brief Get the voltage of the battery.
     * @return Voltage in volts.
     */
    virtual double getVoltage() const;

    /**
     * @brief Get the capacity of the battery.
     * @return Capacity in mAh.
     */
    virtual double getCapacity() const;

    /**
     * @brief Get the current charge of the battery.
     * @return Charge in mAh.
     */
    virtual double getCharge() const;

    /**
     * @brief Get the charge percentage relative to capacity.
     * @return Percentage of charge (0–100).
     */
    virtual double getPercent() const;
};

#endif
