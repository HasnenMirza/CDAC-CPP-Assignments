#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle {
private:
    const double baseRate = 200.0;
    const int baseHours = 2;
    const double hourlyRate = 50.0;
     string discountCode;

public:
    Truck(int hours, string code);
    void calculateCharge() override;
};

#endif // TRUCK_H