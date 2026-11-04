#include <iostream>
#include <cstring>
#include "curr.h"

using namespace std;

int Current::currentCount = 0;

Current::Current() : Account() {
    minInterest = 1.0f;
    minBalance = 1000;
    transactionsPerDay = 5;
    currentCount++;
}

Current::Current(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, int txns)
    : Account(fn, ln, mobnum, mail, p, bal) {
    minInterest = 1.0f;
    minBalance = 1000;
    transactionsPerDay = txns;
    currentCount++;
}

Current::~Current() {
    currentCount--;
}

void Current::createAcc() {
    Account::createAcc();
    cout << "Enter Daily Transactions Limit: ";
    cin >> transactionsPerDay;
    do {
        cout << "Enter Initial Balance (Minimum " << minBalance << "): ";
        cin >> balance;
                cout << "Invalid amount ! Try again ";

    } while (balance < minBalance);
}

void Current::displayAcc() {
    Account::displayAcc();
    cout << "Account Type: Current" << endl;
    cout << "Interest Rate: " << minInterest << "%" << endl;
    cout << "Minimum Balance Required: " << minBalance << endl;
    cout << "Transactions Per Day: " << transactionsPerDay << endl;
}

void Current::withdraw(double amt) {
    if (balance - amt >= minBalance) {
        balance -= amt;
        cout << "Withdrawal successful! Remaining Balance: " << balance << endl;
    } else {
        cout << "Withdrawal failed! Balance cannot be reduced below minimum balance of " << minBalance << endl;
    }
}