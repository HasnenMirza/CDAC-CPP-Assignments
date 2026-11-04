#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    static int nextId; // Static variable to generate unique sid automatically
    int sid;
    char sname[100];
    int age;
    double m1, m2, m3;

public:
    // Default Constructor
    Student() {
        sid = nextId++;
        strcpy(sname, "missing name");
        age = 0;
        m1 = 0.0;
        m2 = 0.0;
        m3 = 0.0;
    }

    // Parameterized Constructor
    Student(const char* name, int studentAge, double mark1, double mark2, double mark3) {
        sid = nextId++;
        strncpy(sname, name, sizeof(sname) - 1);
        sname[sizeof(sname) - 1] = '\0'; 
        age = studentAge;
        m1 = mark1;
        m2 = mark2;
        m3 = mark3;
    }

    // Getter Methods
    int getSid() const { return sid; }
    const char* getSname() const { return sname; }
    int getAge() const { return age; }
    double getM1() const { return m1; }
    double getM2() const { return m2; }
    double getM3() const { return m3; }

    // Setter Methods
    void setSname(const char* name) {
        strncpy(sname, name, sizeof(sname) - 1);
        sname[sizeof(sname) - 1] = '\0';
    }
    void setAge(int studentAge) { age = studentAge; }
    void setM1(double mark1) { m1 = mark1; }
    void setM2(double mark2) { m2 = mark2; }
    void setM3(double mark3) { m3 = mark3; }
    void setMarks(double mark1, double mark2, double mark3) {
        m1 = mark1;
        m2 = mark2;
        m3 = mark3;
    }

    // Method to calculate percentage
    double calculatePercentage() const {
        return (m1 + m2 + m3) / 3.0;
    }

    // Display Method
    void display() const {
        cout << "Student ID : " << sid << endl;
        cout << "Name       : " << sname << endl;
        cout << "Age        : " << age << endl;
        cout << "Marks      : M1=" << m1 << ", M2=" << m2 << ", M3=" << m3 << endl;
        cout << "Percentage : " << calculatePercentage() << "%" << endl;
    }
};

// Initialize static member outside the class
int Student::nextId = 1;

int main() {
    // Creating objects using Parameterized Constructor
    Student s1("sunbeam", 20, 85.5, 90.0, 88.0);
    Student s2("ACTS" , 20 , 35 , 60, 88);

    // Creating object using Default Constructor and setting values via setters
    Student s3;
    s3.setSname("Charlie");
    s3.setAge(19);
    s3.setMarks(92.0, 89.5, 94.0);

    // Displaying Student details
    cout << "--- Student Details ---" << endl;
    s1.display();
    cout << endl;

    s2.display();
    cout << endl;

    s3.display();
    cout << endl;

    return 0;
}
