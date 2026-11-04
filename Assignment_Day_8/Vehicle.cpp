#include "Vehicle.h"

// Initialize static member variable
int Vehicle::receiptCount = 0;

Vehicle::Vehicle(int hours) : parkingHours(hours) {
    receiptCount++;
}

Vehicle::~Vehicle() {}

int Vehicle::getReceiptCount() {
    return receiptCount;
}