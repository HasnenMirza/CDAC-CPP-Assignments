#include <iostream>
#include <string>
#include <cctype>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

int main() {
    char choice;

    do {
        char vehicleType;
        int hours;

        // Input Validation: Vehicle Type
        while (true) {
            std::cout << "Enter type of Vehicle (C for Car, T for Truck): ";
            std::cin >> vehicleType;
            vehicleType = std::toupper(vehicleType);

            if (vehicleType == 'C' || vehicleType == 'T') {
                break;
            }
            std::cout << "Invalid vehicle type! Please try again.\n";
        }

        // Input Validation: Parking Hours
        while (true) {
            std::cout << "Enter parking hours: ";
            std::cin >> hours;

            if (hours > 0) {
                break;
            }
            std::cout << "Parking hours must be positive! Please try again.\n";
        }

        Vehicle* vehiclePtr = nullptr;

        if (vehicleType == 'C') {
            vehiclePtr = new Car(hours);
        } else if (vehicleType == 'T') {
            std::cin.ignore(); // Clear newline buffer from cin
            std::string code;
            std::cout << "Enter discount code if available (or press Enter to skip): ";
            std::getline(std::cin, code);
            vehiclePtr = new Truck(hours, code);
        }

        // Dynamic Binding / Runtime Polymorphism Call
        if (vehiclePtr != nullptr) {
            vehiclePtr->calculateCharge();
            delete vehiclePtr; // Clean up memory
        }

        // Ask user if they want to calculate another receipt or exit
        std::cout << "\nDo you want to enter another vehicle? (Y to continue, any other key to exit): ";
        std::cin >> choice;
        choice = std::toupper(choice);
        std::cout << "\n----------------------------------------\n\n";

    } while (choice == 'Y');

    std::cout << "Exiting program. Total receipts generated: " << Vehicle::getReceiptCount() << "\n";

    return 0;
}