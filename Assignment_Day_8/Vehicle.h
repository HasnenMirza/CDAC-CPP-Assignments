#ifndef VEHICLE_H
#define VEHICLE_H

// Abstract Base Class
class Vehicle {
protected:
    int parkingHours;
    static int receiptCount; // Static data member to count total receipts

public:
    Vehicle(int hours);
    virtual ~Vehicle();

    // Pure virtual function for runtime polymorphism
    virtual void calculateCharge() = 0;

    static int getReceiptCount();
};

// Inline function to compute extra parking charges beyond base hours
inline double calculateExtraCharge(int totalHours, int baseHours, double hourlyRate) {
    if (totalHours > baseHours) {
        return (totalHours - baseHours) * hourlyRate;
    }
    return 0.0;
}

// Function template to validate discount codes
template <typename T>
bool validateDiscountCode(T inputCode, T validCode) {
    return inputCode == validCode;
}

#endif // VEHICLE_H