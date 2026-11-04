#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class Saving : public Account {
private:
    int Cheque_no;
    static int savingCount;

protected:
    float minInterest;
    int minBalance;

public:
    Saving();
    Saving(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, int chqNo);
    ~Saving();

    void createAcc();
    void displayAcc();
    void withdraw(double amt);

    int getAccountType() const { return 1; }
    static int getSavingCount() { return savingCount; }
};

#endif