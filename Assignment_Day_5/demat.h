#ifndef DEMAT_H
#define DEMAT_H

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

struct ShareDetails {
    string shareName;
    int numOfShares;
    double buyPrice;
    string buyDate;
    double sellPrice;
    string sellDate;
};

class Demat : public Account {
private:
    ShareDetails share;
    static int dematCount;

public:
    Demat();
    Demat(const char* fn, const char* ln, string mobnum, string mail, int p, double bal, ShareDetails s);
    ~Demat();

    void createAcc();
    void displayAcc();

    int getAccountType() const { return 3; }
    static int getDematCount() { return dematCount; }
};

#endif