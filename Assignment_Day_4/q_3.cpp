#include<iostream>
using namespace std;

class Time{
    private:
    int hrs;
    int mins;
    
    public:
    // Default Constructor
    Time() {
        hrs = 0;
        mins = 0;
    }

    // Parameterized Constructor
    Time(int h, int m){
        hrs = h;
        mins = m;
    }

    // Copy Constructor
    Time(const Time &t) {
        hrs = t.hrs;
        mins = t.mins;
    }

    int gethrs() const { 
        return hrs; 
    }

    int getmin() const { 
        return mins; 
    }

    // + overloading
    Time operator+(const Time &t) const {
        Time temp;
        temp.hrs = hrs + t.hrs;
        temp.mins = mins + t.mins;
        if (temp.mins >= 60) {
            temp.hrs += temp.mins / 60;
            temp.mins %= 60;
        }
        return temp;
    }

    // - overloading
    Time operator-(const Time &t) const {
        Time temp;
        int totalMins1 = hrs * 60 + mins;
        int totalMins2 = t.hrs * 60 + t.mins;
        int diff = totalMins1 - totalMins2;

        if (diff < 0) diff = 0; // Prevent negative time

        temp.hrs = diff / 60;
        temp.mins = diff % 60;
        return temp;
    }

    // ++t (prefix increment: adds 1 minute)
    Time& operator++() {
        mins++;
        if (mins >= 60) {
            hrs += mins / 60;
            mins %= 60;
        }
        return *this; 
    }

    // t++ (postfix increment: adds 1 minute)
    Time operator++(int) {
        Time temp = *this; 
        ++(*this);         
        return temp;       
    }

    // --t (prefix decrement: subtract 1 minute)
    Time& operator--() {
        mins--;
        if (mins < 0) {
            mins = 59;
            hrs--;
        }
        if (hrs < 0) {
            hrs = 0;
            mins = 0;
        }
        return *this;
    }

    // t-- (postfix decrement: subtract 1 minute)
    Time operator--(int) {
        Time temp = *this; 
        --(*this);         
        return temp;       
    }

    // Overloaded Assignment Operator
    Time& operator=(const Time &t) {
        if (this == &t) {
            return *this;
        }
        hrs = t.hrs;
        mins = t.mins;
        return *this;
    }

    // Display member function
    void display() const {
        cout << hrs << " hours " << mins << " minutes" << endl;
    }

    friend ostream& operator<<(ostream& out , const Time &t);
    friend istream& operator>>(istream& in , Time &t); 
};

ostream& operator<<(ostream& out , const Time &t){
    out << t.hrs << " hours " << t.mins << " minutes";
    return out;
}

istream& operator>>(istream& in , Time &t){
    cout << "Enter Hours: ";
    in >> t.hrs;
    cout << "Enter Minutes: ";
    in >> t.mins;
    return in;
}

int main(){
    Time t1(3, 30), t2(1, 45), t3;
    int choice;

    do {
        cout << "\n=================================" << endl;
        cout << "     TEST TIME CLASS MENU           " << endl;
        cout << "=================================" << endl;
        cout << "1. Display Current Time Objects" << endl;
        cout << "2. Input New Time Objects (t1 & t2)" << endl;
        cout << "3. Add (t3 = t1 + t2)" << endl;
        cout << "4. Subtract (t3 = t1 - t2)" << endl;
        cout << "5. Assignment (t3 = t1)" << endl;
        cout << "6. Chained Assignment (t1 = t2 = t3)" << endl;
        cout << "7. Prefix Increment (++t1)" << endl;
        cout << "8. Postfix Increment (t1++)" << endl;
        cout << "9. Prefix Decrement (--t1)" << endl;
        cout << "10. Postfix Decrement (t1--)" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n---------------------------------" << endl;
        switch(choice) {
            case 1:
                cout << "t1: " << t1 << endl;
                cout << "t2: " << t2 << endl;
                cout << "t3: " << t3 << endl;
                break;

            case 2:
                cout << "Input for t1:" << endl;
                cin >> t1;
                cout << "\nInput for t2:" << endl;
                cin >> t2;
                cout << "\nUpdated Objects:" << endl;
                cout << "t1: " << t1 << "\nt2: " << t2 << endl;
                break;

            case 3:
                t3 = t1 + t2;
                cout << "Result (t1 + t2): " << t3 << endl;
                break;

            case 4:
                t3 = t1 - t2;
                cout << "Result (t1 - t2): " << t3 << endl;
                break;

            case 5:
                t3 = t1;
                cout << "t3 after (t3 = t1): " << t3 << endl;
                break;

            case 6:
                cout << "Before Chained Assignment -> t1: " << t1 << " | t2: " << t2 << " | t3: " << t3 << endl;
                t1 = t2 = t3;
                cout << "After (t1 = t2 = t3)       -> t1: " << t1 << " | t2: " << t2 << " | t3: " << t3 << endl;
                break;

            case 7:
                cout << "Before ++t1: " << t1 << endl;
                ++t1;
                cout << "After ++t1:  " << t1 << endl;
                break;

            case 8: {
                cout << "Before t1++: " << t1 << endl;
                Time oldVal = t1++;
                cout << "Returned Old Value: " << oldVal << endl;
                cout << "New Updated Value:  " << t1 << endl;
                break;
            }

            case 9:
                cout << "Before --t1: " << t1 << endl;
                --t1;
                cout << "After --t1:  " << t1 << endl;
                break;

            case 10: {
                cout << "Before t1--: " << t1 << endl;
                Time oldVal = t1--;
                cout << "Returned Old Value: " << oldVal << endl;
                cout << "New Updated Value:  " << t1 << endl;
                break;
            }

            case 11:
                cout << "Exiting Menu..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 11);

    return 0;
}