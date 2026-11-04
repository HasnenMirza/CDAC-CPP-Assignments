// Write a program to save employees in map, id as key and object as a value
// Employee contains id and name
// 1. Add a new employee
// 2. Delete employee by id
// 3. Display all
// 4. Display by id
// 5. Display by name

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool addEmp(int id, string name, map<int, string>& m) {
    return m.insert({id, name}).second; // insert returns pair<iterator,bool>
}

bool deleteEmp(int id, map<int, string>& m) {
    if (m.find(id) == m.end()) return false; // not found
    return m.erase(id) > 0; // erase returns count of removed elements
}

void displayAll(const map<int, string>& m) {
    if (m.empty()) {
        cout << "No employees found!" << endl;
        return;
    }
    cout << "Employee List:" << endl;
    for (auto& emp : m) {
        cout << "ID: " << emp.first << ", Name: " << emp.second << endl;
    }
}

void displayById(int id, const map<int, string>& m) {
    auto it = m.find(id);
    if (it != m.end()) {
        cout << "Employee found -> ID: " << it->first << ", Name: " << it->second << endl;
    } else {
        cout << "Employee with ID " << id << " not found!" << endl;
    }
}

void displayByName(string name, const map<int, string>& m) {
    bool found = false;
    for (auto& emp : m) {
        if (emp.second == name) {
            cout << "Employee found -> ID: " << emp.first << ", Name: " << emp.second << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Employee with name " << name << " not found!" << endl;
    }
}

int main() {
    map<int, string> m;
    int choice, id;
    string name;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Add a new employee\n"
             << "2. Delete employee by id\n"
             << "3. Display all\n"
             << "4. Display by id\n"
             << "5. Display by name\n"
             << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                if (addEmp(id, name, m))
                    cout << "Employee added successfully!" << endl;
                else
                    cout << "Error: Employee ID already exists!" << endl;
                break;

            case 2:
                cout << "Enter ID to delete: ";
                cin >> id;
                if (deleteEmp(id, m))
                    cout << "Employee deleted successfully!" << endl;
                else
                    cout << "Error: Employee ID not found!" << endl;
                break;

            case 3:
                displayAll(m);
                break;

            case 4:
                cout << "Enter ID to search: ";
                cin >> id;
                displayById(id, m);
                break;

            case 5:
                cout << "Enter Name to search: ";
                cin >> name;
                displayByName(name, m);
                break;

            case 6:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please enter between 1-6." << endl;
        }
    }
}
