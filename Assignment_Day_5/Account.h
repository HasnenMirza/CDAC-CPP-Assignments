#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    static int nextAccId;
    int accId;
    char* fname;
    char* lname;
    string mobno;
    string email;
    int pin;
    double balance;

public:
    Account();
    Account(const char* fn, const char* ln, string mobnum, string mail, int p, double bal);
    Account(const Account& other);
    Account& operator=(const Account& other);
    virtual ~Account();

    int getAccId() const;
    double getBalance() const;
    bool verifyPin(int p) const;
    void setPin(int newPin);

    virtual void createAcc();
    virtual void displayAcc();
    virtual void withdraw(double amt);
    virtual void deposit(double amt);

    virtual int getAccountType() const = 0;
};

#endif