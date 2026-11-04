#include <iostream>
#include "Truck.h"

Truck::Truck(int hours, std::string code) : Vehicle(hours), discountCode(code) {}

void Truck::calculateCharge() {
    double extraCharge = calculateExtraCharge(parkingHours, baseHours, hourlyRate);
    double totalCharge = baseRate + extraCharge;

    // Template function usage for discount validation
    if (validateDiscountCode<std::string>(discountCode, "TRUCK50")) {
        totalCharge -= 50.0;
    }

    std::cout << "\nVehicle type = Truck\n";
    std::cout << "Extra charge = Rs. " << extraCharge << "\n";
    std::cout << "Total Charge after discount = Rs. " << totalCharge << "\n";
    std::cout << "Receipts generated so far: " << getReceiptCount() << "\n";
}