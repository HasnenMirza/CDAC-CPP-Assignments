#include "Address.h" // Fixed typo (was Addresss.h)
#include <iostream>
#include <cstring>
using namespace std;

// Default constructor
Address::Address() {
    street = new char[1]{'\0'};
    city = new char[1]{'\0'};
    state = new char[1]{'\0'};
    pin = 0;
}

// Parametric constructor
Address::Address(const char* s, const char* c, const char* st, int p) {
    street = new char[strlen(s) + 1];
    strcpy(street, s);

    city = new char[strlen(c) + 1];
    strcpy(city, c);

    state = new char[strlen(st) + 1];
    strcpy(state, st); // Fixed typo: was strcpy(city, st)

    pin = p;
}

// Copy Constructor
Address::Address(const Address& other) {
    street = new char[strlen(other.street) + 1];
    strcpy(street, other.street);

    city = new char[strlen(other.city) + 1];
    strcpy(city, other.city);

    state = new char[strlen(other.state) + 1];
    strcpy(state, other.state);

    pin = other.pin;
}

// Assignment Operator
Address& Address::operator=(const Address& other) {
    if (this != &other) {
        delete[] street;
        delete[] city;
        delete[] state;

        street = new char[strlen(other.street) + 1];
        strcpy(street, other.street);

        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);

        state = new char[strlen(other.state) + 1];
        strcpy(state, other.state);

        pin = other.pin;
    }
    return *this;
}

// Destructor
Address::~Address() {
    delete[] street;
    delete[] city;
    delete[] state;
}

void Address::setaddress(const char* s, const char* c, const char* st, int p) {
    delete[] street;
    delete[] city;
    delete[] state;

    street = new char[strlen(s) + 1];
    strcpy(street, s);

    city = new char[strlen(c) + 1];
    strcpy(city, c);

    state = new char[strlen(st) + 1];
    strcpy(state, st);

    pin = p; // Added missing pin assignment
}

// Display
void Address::display() const {
    cout << "Street: " << street << endl;
    cout << "City:   " << city << endl;
    cout << "State:  " << state << endl;
    cout << "PIN:    " << pin << endl;
}