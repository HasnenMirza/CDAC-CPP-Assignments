#ifndef CURRENT_H
#define CURRENT_H

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class Current : public Account {
private:
    int transactionsPerDay;
    static int currentCount;

protected:
    float minInterest;
    int minBalance;

public:
    Current();
    Current(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, int txns);
    ~Current();

    void createAcc();
    void displayAcc();
    void withdraw(double amt);

    int getAccountType() const { return 2; }
    static int getCurrentCount() { return currentCount; }
};

#endif