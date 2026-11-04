#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STUDENTS = 100;

class Student {
private:
    static int nextId; // Static counter for auto-generating unique ID
    int sid;
    char sname[100];
    int age;
    double m1, m2, m3;
    double gpa;

public:
    // Default Constructor
    Student() {
        sid = nextId++;
        strcpy(sname, "missing name");
        age = 0;
        m1 = 0.0;
        m2 = 0.0;
        m3 = 0.0;
        gpa = 0.0;
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
        calculateGPA(); // Calculate GPA upon creation
    }

    // Function to calculate and update GPA
    // gpa = (1/3)*m1 + (1/2)*m2 + (1/4)*m3
    // Note: Use floating point numbers (1.0/3.0) to prevent integer division (1/3 = 0)
    double calculateGPA() {
        gpa = (1.0 / 3.0) * m1 + (1.0 / 2.0) * m2 + (1.0 / 4.0) * m3;
        return gpa;
    }

    // Getters
    int getSid() const { return sid; }
    const char* getSname() const { return sname; }
    int getAge() const { return age; }
    double getM1() const { return m1; }
    double getM2() const { return m2; }
    double getM3() const { return m3; }
    double getGPA() const { return gpa; }

    // Setters
    void setSname(const char* name) {
        strncpy(sname, name, sizeof(sname) - 1);
        sname[sizeof(sname) - 1] = '\0';
    }
    void setAge(int studentAge) { age = studentAge; }
    void setM1(double mark1) { m1 = mark1; calculateGPA(); }
    void setM2(double mark2) { m2 = mark2; calculateGPA(); }
    void setM3(double mark3) { m3 = mark3; calculateGPA(); }
    void setMarks(double mark1, double mark2, double mark3) {
        m1 = mark1;
        m2 = mark2;
        m3 = mark3;
        calculateGPA();
    }

    // Display Method
    void display() const {
        cout << "------------------------------------" << endl;
        cout << "Student ID : " << sid << endl;
        cout << "Name       : " << sname << endl;
        cout << "Age        : " << age << endl;
        cout << "Marks      : M1=" << m1 << ", M2=" << m2 << ", M3=" << m3 << endl;
        cout << "GPA        : " << gpa << endl;
        cout << "------------------------------------" << endl;
    }
};

// Initialize static variable
int Student::nextId = 1;

// Function Prototypes
void addStudent(Student* studentList[], int& count);
void displayAllStudents(Student* studentList[], int count);
void searchById(Student* studentList[], int count);
void searchByName(Student* studentList[], int count);
void calculateStudentGPA(Student* studentList[], int count);

int main() {
    Student* studentList[MAX_STUDENTS]; // Array of pointers
    int studentCount = 0;
    int choice;

    do {
        cout << "\n================ STUDENT MANAGEMENT SYSTEM ================" << endl;
        cout << "0. Add a New Student" << endl;
        cout << "1. Display All Students" << endl;
        cout << "2. Search by ID" << endl;
        cout << "3. Search by Name" << endl;
        cout << "4. Calculate GPA of a Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (0-5): ";
        cin >> choice;

        switch (choice) {
            case 0:
                addStudent(studentList, studentCount);
                break;
            case 1:
                displayAllStudents(studentList, studentCount);
                break;
            case 2:
                searchById(studentList, studentCount);
                break;
            case 3:
                searchByName(studentList, studentCount);
                break;
            case 4:
                calculateStudentGPA(studentList, studentCount);
                break;
            case 5:
                cout << "\nExiting Program. Freeing allocated memory..." << endl;
                // Deallocate memory for all dynamically allocated objects
                for (int i = 0; i < studentCount; i++) {
                    delete studentList[i];
                }
                break;
            default:
                cout << "\nInvalid choice! Please enter a valid menu option." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new student using dynamic allocation
void addStudent(Student* studentList[], int& count) {
    if (count >= MAX_STUDENTS) {
        cout << "\n[!] List is full. Cannot add more students." << endl;
        return;
    }

    char name[100];
    int age;
    double m1, m2, m3;

    cin.ignore();
    cout << "\nEnter Student Name: ";
    cin.getline(name, 100);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Marks for Subject 1 (M1): ";
    cin >> m1;
    cout << "Enter Marks for Subject 2 (M2): ";
    cin >> m2;
    cout << "Enter Marks for Subject 3 (M3): ";
    cin >> m3;

    // Dynamically allocate memory and assign pointer to array
    studentList[count] = new Student(name, age, m1, m2, m3);
    count++;

    cout << "\n[+] Student added successfully! Assigned ID: " << studentList[count - 1]->getSid() << endl;
}

// Function to display all students
void displayAllStudents(Student* studentList[], int count) {
    if (count == 0) {
        cout << "\n[!] No student records found!" << endl;
        return;
    }

    cout << "\n--- Displaying All " << count << " Student(s) ---" << endl;
    for (int i = 0; i < count; i++) {
        studentList[i]->display();
    }
}

// Function to search student by ID
void searchById(Student* studentList[], int count) {
    if (count == 0) {
        cout << "\n[!] No student records found!" << endl;
        return;
    }

    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < count; i++) {
        if (studentList[i]->getSid() == searchId) {
            cout << "\n[+] Record Found:" << endl;
            studentList[i]->display();
            return;
        }
    }
    cout << "\n[-] Student with ID " << searchId << " not found." << endl;
}

// Function to search student by Name
void searchByName(Student* studentList[], int count) {
    if (count == 0) {
        cout << "\n[!] No student records found!" << endl;
        return;
    }

    cin.ignore();
    char searchName[100];
    cout << "\nEnter Student Name to search: ";
    cin.getline(searchName, 100);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(studentList[i]->getSname(), searchName) == 0) {
            cout << "\n[+] Record Found:" << endl;
            studentList[i]->display();
            found = true;
        }
    }

    if (!found) {
        cout << "\n[-] Student with name '" << searchName << "' not found." << endl;
    }
}

// Function to calculate and show GPA of a student
void calculateStudentGPA(Student* studentList[], int count) {
    if (count == 0) {
        cout << "\n[!] No student records found!" << endl;
        return;
    }

    int searchId;
    cout << "\nEnter Student ID to calculate GPA: ";
    cin >> searchId;

    for (int i = 0; i < count; i++) {
        if (studentList[i]->getSid() == searchId) {
            double calculatedGPA = studentList[i]->calculateGPA();
            cout << "\n[+] GPA for " << studentList[i]->getSname() 
                 << " (ID: " << searchId << ") is: " << calculatedGPA << endl;
            return;
        }
    }
    cout << "\n[-] Student with ID " << searchId << " not found." << endl;
}