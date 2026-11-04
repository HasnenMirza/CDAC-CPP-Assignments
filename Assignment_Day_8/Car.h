#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    const double baseRate = 100.0;
    const int baseHours = 3;
    const double hourlyRate = 30.0;

public:
    Car(int hours);
    void calculateCharge() override;
};

#endif // CAR_H