#include <iostream>
#include <cstring>
#include "demat.h"

using namespace std;

int Demat::dematCount = 0;

Demat::Demat() : Account() {
    share = {"", 0, 0.0, "", 0.0, ""};
    dematCount++;
}

Demat::Demat(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, ShareDetails s)
    : Account(fn, ln, mobnum, mail, p, bal), share(s) {
    dematCount++;
}

Demat::~Demat() {
    dematCount--;
}

void Demat::createAcc() {
    Account::createAcc();
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Enter Share Name: ";
    cin >> share.shareName;
    cout << "Enter Number of Shares: ";
    cin >> share.numOfShares;
    cout << "Enter Buying Price: ";
    cin >> share.buyPrice;
    cout << "Enter Date of Purchase: ";
    cin >> share.buyDate;
    cout << "Enter Selling Price: ";
    cin >> share.sellPrice;
    cout << "Enter Date of Selling: ";
    cin >> share.sellDate;
}

void Demat::displayAcc() {
    Account::displayAcc();
    cout << "Account Type: Demat" << endl;
    cout << "Share Name: " << share.shareName << endl;
    cout << "Number of Shares: " << share.numOfShares << endl;
    cout << "Buying Price: " << share.buyPrice << " (Date: " << share.buyDate << ")" << endl;
    cout << "Selling Price: " << share.sellPrice << " (Date: " << share.sellDate << ")" << endl;
}