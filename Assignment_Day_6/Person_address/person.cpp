#include "person.h"
#include <iostream>
using namespace std;

// Initialize static member for auto-generated ID starting at 101
int person::count = 100;

// Default Constructor
person::person() : id(++count), name(""), addr() {}

// Parameterized Constructor
person::person(string n, Address add) : id(++count), name(n), addr(add) {}

// Destructor
person::~person() {}

int person::getId() const {
    return id;
}

string person::getname() const {
    return name;
}

const Address& person::getaddress() const {
    return addr;
}

void person::setaddress(const Address & newaddress) {
    addr = newaddress;
}

void person::display() const {
    cout << "ID: " << id << " | Name: " << name << " | Address: ";
    addr.display();
    cout << endl;
}