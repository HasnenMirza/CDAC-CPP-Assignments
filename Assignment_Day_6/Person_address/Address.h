#ifndef ADDRESS_H
#define ADDRESS_H

class Address {

   private:
        char* street;
        char* city;
        char* state;
        int pin;

    public:
        Address();
        Address(const char* s, const char* c, const char* st, int p);

        // Copy Constructor & Assignment Operator (Rule of Three)
        Address(const Address& other);
        Address& operator=(const Address& other);

        void display() const;
        void setaddress(const char* s, const char* c, const char* st, int p);
        ~Address();
};

#endif