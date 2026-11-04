#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

// Default Constructor
student::student() {
    cout << "In Student default constructor: " << endl;
    sid = 0;
    sname = new char[strlen("Xyz") + 1];
    strcpy(sname, "Xyz");    
    sage = 0;
    m1 = 0.0f;
    m2 = 0.0f;
    m3 = 0.0f;
}

// Parameterized Constructor
student::student(const char *name, int id, int age, float mark1, float mark2, float mark3) {
    sid = id;
    sage = age;
    m1 = mark1;
    m2 = mark2;
    m3 = mark3;
    sname = new char[strlen(name) + 1];
    strcpy(sname, name);
}

// Setters
void student::setSid(int id) { sid = id; }

void student::setName(const char *name) {
    if (sname != nullptr) {
        delete[] sname;
    }
    sname = new char[strlen(name) + 1];
    strcpy(sname, name);
}

void student::setAge(int age) { sage = age; }
void student::setM1(float mark1) { m1 = mark1; }
void student::setM2(float mark2) { m2 = mark2; }
void student::setM3(float mark3) { m3 = mark3; }

// Getters
int student::getSid() const { return sid; }
int student::getAge() const { return sage; }
const char* student::getName() const { return sname; }

// Display implementation
void student::display() const {
    cout << "Sid: " << sid << endl;
    cout << "SName: " << (sname ? sname : "") << endl;
    cout << "Age: " << sage << endl;
    cout << "mark1: " << m1 << endl;
    cout << "mark2: " << m2 << endl;
    cout << "mark3: " << m3 << endl;
    cout << "---------------------" << endl;
}

// Destructor
student::~student() {
    cout << "In Student destructor" << endl;
    delete[] sname;
}
