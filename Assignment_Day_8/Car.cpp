#include <iostream>
#include "Car.h"

Car::Car(int hours) : Vehicle(hours) {}

void Car::calculateCharge() {
    double extraCharge = calculateExtraCharge(parkingHours, baseHours, hourlyRate);
    double totalCharge = baseRate + extraCharge;

    std::cout << "\nVehicle type = Car\n";
    std::cout << "Extra charge = Rs. " << extraCharge << "\n";
    std::cout << "Total Parking Charge = Rs. " << totalCharge << "\n";
    std::cout << "Receipts generated so far: " << getReceiptCount() << "\n";
}