#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

int Account::nextAccId = 1001;

Account::Account() {
    accId = nextAccId++;
    fname = nullptr;
    lname = nullptr;
    mobno = "";
    email = "";
    pin = 0;
    balance = 0.0;
}

Account::Account(const char* fn, const char* ln, string mobnum, string mail, int p, double bal) {
    accId = nextAccId++;
    fname = new char[strlen(fn) + 1];
    strcpy(fname, fn);
    lname = new char[strlen(ln) + 1];
    strcpy(lname, ln);
    mobno = mobnum;
    email = mail;
    pin = p;
    balance = bal;
}

Account::Account(const Account& other) {
    accId = other.accId;
    mobno = other.mobno;
    email = other.email;
    pin = other.pin;
    balance = other.balance;
    if (other.fname) {
        fname = new char[strlen(other.fname) + 1];
        strcpy(fname, other.fname);
    } else {
        fname = nullptr;
    }
    if (other.lname) {
        lname = new char[strlen(other.lname) + 1];
        strcpy(lname, other.lname);
    } else {
        lname = nullptr;
    }
}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        delete[] fname;
        delete[] lname;
        accId = other.accId;
        mobno = other.mobno;
        email = other.email;
        pin = other.pin;
        balance = other.balance;
        if (other.fname) {
            fname = new char[strlen(other.fname) + 1];
            strcpy(fname, other.fname);
        } else {
            fname = nullptr;
        }
        if (other.lname) {
            lname = new char[strlen(other.lname) + 1];
            strcpy(lname, other.lname);
        } else {
            lname = nullptr;
        }
    }
    return *this;
}

Account::~Account() {
    delete[] fname;
    delete[] lname;
}

int Account::getAccId() const {
    return accId;
}

double Account::getBalance() const {
    return balance;
}

bool Account::verifyPin(int p) const {
    return pin == p;
}

void Account::setPin(int newPin) {
    pin = newPin;
}

void Account::createAcc() {
    char temp[100];
    delete[] fname;
    delete[] lname;

    cout << "Enter first name: ";
    cin >> temp;
    fname = new char[strlen(temp) + 1];
    strcpy(fname, temp);

    cout << "Enter last name: ";
    cin >> temp;
    lname = new char[strlen(temp) + 1];
    strcpy(lname, temp);

    cout << "Enter Mobile No.: ";
    cin >> mobno;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Create 4 digit PIN: ";
    cin >> pin;
}

void Account::displayAcc() {
    cout << "Account ID: " << accId << endl;
    cout << "Account Name: " << (fname ? fname : "") << " " << (lname ? lname : "") << endl;
    cout << "Mobile number: " << mobno << endl;
    cout << "E-mail: " << email << endl;
    cout << "Balance: " << balance << endl;
}

void Account::deposit(double amt) {
    if (amt > 0) {
        balance += amt;
        cout << "Deposit successful! New Balance: " << balance << endl;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

void Account::withdraw(double amt) {
    if (balance >= amt) {
        balance -= amt;
        cout << "Withdrawal successful! Remaining Balance: " << balance << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}