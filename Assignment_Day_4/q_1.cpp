#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    static int count;

    private:
        int EmpId;
        char* name;
        int bonus;
        int basicSalary;

    public:
        int hourly_rate;
        int extra_hours_worked;

        // Default Constructor
        Employee() {
            EmpId = ++count;
            const char* defaultName = "missing name";
            name = new char[strlen(defaultName) + 1];
            strcpy(name, defaultName);
            bonus = 0;
            basicSalary = 10000;
            hourly_rate = 50;
            extra_hours_worked = 0;
        }

        // Parameterized Constructor
        Employee(const char* nm, int bon, int bsalary, int E_hrs, int h_rate = 50) {
            EmpId = ++count;
            name = new char[strlen(nm) + 1];
            strcpy(name, nm);
            bonus = bon;
            basicSalary = bsalary;
            extra_hours_worked = E_hrs;
            hourly_rate = h_rate;
        }

        // Destructor to prevent memory leak
        ~Employee() {
            delete[] name;
        }

        int Overtime_pay(int no_of_hours) {
            return hourly_rate * no_of_hours;
        }

        // 1. Calculate salary using monthly basic salary
        void calculateSalary(int bSalary) {
            basicSalary = bSalary;
            cout << "Basic salary is: " << basicSalary << endl;
        }

        // 2. Calculate salary using basic salary and bonus
        void calculateSalary(int bSalary, int b) {
            bonus = b;
            int salary = bSalary + bonus;
            cout << "Salary with Bonus is: " << salary << endl;
        }

        // 3. Calculate salary using basic salary, bonus, and overtime amount
        void calculateSalary(int bSalary, int b, int Extra_Hour) {
            int salary = bSalary + b + Overtime_pay(Extra_Hour);
            cout << "Salary with Bonus and Overtime is: " << salary << endl;
        }

        // 4. Calculate salary for an employee using hourly rate and number of hours worked
        void calculateSalary(double hRate, int totalHours) {
            double salary = hRate * totalHours;
            cout << "Salary calculated using Hourly Rate (" << hRate << ") and Hours (" << totalHours << ") is: " << salary << endl;
        }

        // Overloading >> operator to take input
        friend istream& operator>>(istream& in, Employee& e) {
            char temp[100];
            cout << "Enter Name: ";
            in >> temp;
            
            delete[] e.name; // free existing memory
            e.name = new char[strlen(temp) + 1];
            strcpy(e.name, temp);

            cout << "Enter Basic Salary: ";
            in >> e.basicSalary;
            cout << "Enter Bonus: ";
            in >> e.bonus;
            cout << "Enter Extra Hours Worked: ";
            in >> e.extra_hours_worked;

            return in;
        }

        // Overloading << operator to display output
        friend ostream& operator<<(ostream& out, const Employee& e) {
            out << "\n--- Employee Details ---" << endl;
            out << "Emp ID: " << e.EmpId << endl;
            out << "Name: " << e.name << endl;
            out << "Basic Salary: " << e.basicSalary << endl;
            out << "Bonus: " << e.bonus << endl;
            out << "Extra Hours Worked: " << e.extra_hours_worked << endl;
            return out;
        }
};

// Definition of static count
int Employee::count = 0;

int main() {
    Employee e1("John", 2000, 25000, 10);

    cout << e1;

    cout << "\n--- Testing calculateSalary() Overloads function ---" << endl;
    
    // 1. Basic salary
    e1.calculateSalary(25000);

    // 2. Basic salary + Bonus
    e1.calculateSalary(25000, 3000);

    // 3. Basic salary + Bonus + Overtime
    e1.calculateSalary(25000, 3000, 5);

    // 4. Hourly rate + Total hours worked
    e1.calculateSalary(50.5, 160);

    cout << "\n--- Testing >> and << Operator ---" << endl;
    Employee e2;
    cin >> e2;
    cout << e2;

    return 0;
}