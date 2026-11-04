#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;
#include "Address.h"

class person {

    private:
        static int count;
        int id;
        string name;
        Address addr;

    public:
        person();
        person(string n, Address addr);

        ~person();

        void display() const;
        const Address& getaddress() const;
        void setaddress(const Address & newaddress);
        int getId() const;
        string getname() const;

};

#endif