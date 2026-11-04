#include <iostream>
#include <cstring>
#include "Saving.h"

using namespace std;

int Saving::savingCount = 0;

Saving::Saving() : Account() {
    minInterest = 4.0f;
    minBalance = 20000;
    Cheque_no = 0;
    savingCount++;
}

Saving::Saving(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, int chqNo)
    : Account(fn, ln, mobnum, mail, p, bal) {
    minInterest = 4.0f;
    minBalance = 20000;
    Cheque_no = chqNo;
    savingCount++;
}

Saving::~Saving() {
    savingCount--;
}

void Saving::createAcc() {
    Account::createAcc();
    cout << "Enter Cheque Book No: ";
    cin >> Cheque_no;
    do {
        cout << "Enter Initial Balance (Minimum " << minBalance << "): ";
        cin >> balance;
    } while (balance < minBalance);
}

void Saving::displayAcc() {
    Account::displayAcc();
    cout << "Account Type: Saving" << endl;
    cout << "Interest Rate: " << minInterest << "%" << endl;
    cout << "Minimum Balance Required: " << minBalance << endl;
    cout << "Cheque Book No: " << Cheque_no << endl;
}

void Saving::withdraw(double amt) {
    if (balance - amt >= minBalance) {
        balance -= amt;
        cout << "Withdrawal successful! Remaining Balance: " << balance << endl;
    } else {
        cout << "Withdrawal failed! Balance cannot be reduced below minimum balance of " << minBalance << endl;
    }
}