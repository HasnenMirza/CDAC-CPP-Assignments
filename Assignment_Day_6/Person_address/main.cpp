#include <iostream>
#include <string>
#include "person.h"
#include "Address.h"

using namespace std;

void addPerson(person* people[], int& total) {
    string name, street, city, state;
    int pin;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Street: ";
    getline(cin, street);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter Pin Code: ";
    cin >> pin;

    Address addr(street.c_str(), city.c_str(), state.c_str(), pin);
    people[total++] = new person(name, addr);
    cout << "Person added successfully with ID: " << people[total - 1]->getId() << endl;
}

void displayAll(person* people[], int total) {
    if (total == 0) {
        cout << "No records available.\n";
        return;
    }
    for (int i = 0; i < total; ++i) {
        people[i]->display();
    }
}

void searchById(person* people[], int total) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < total; ++i) {
        if (people[i]->getId() == id) {
            cout << "Record Found:\n";
            people[i]->display();
            return;
        }
    }
    cout << "Person with ID " << id << " not found.\n";
}

void searchByName(person* people[], int total) {
    string name;
    cin.ignore();
    cout << "Enter Name to search: ";
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < total; ++i) {
        if (people[i]->getname() == name) {
            people[i]->display();
            found = true;
        }
    }
    if (!found) cout << "No person found with name: " << name << endl;
}

void modifyAddress(person* people[], int total) {
    int id;
    cout << "Enter Person ID to modify address: ";
    cin >> id;

    for (int i = 0; i < total; ++i) {
        if (people[i]->getId() == id) {
            string street, city, state;
            int pin;

            cin.ignore();
            cout << "Enter New Street: ";
            getline(cin, street);

            cout << "Enter New City: ";
            getline(cin, city);

            cout << "Enter New State: ";
            getline(cin, state);

            cout << "Enter New Pin Code: ";
            cin >> pin;

            people[i]->setaddress(Address(street.c_str(), city.c_str(), state.c_str(), pin));
            cout << "Address updated successfully.\n";
            return;
        }
    }
    cout << "Person ID not found.\n";
}

void findAddressById(person* people[], int total) {
    int id;
    cout << "Enter Person ID: ";
    cin >> id;

    for (int i = 0; i < total; ++i) {
        if (people[i]->getId() == id) {
            cout << "Address Details:\n";
            people[i]->getaddress().display();
            cout << endl;
            return;
        }
    }
    cout << "Person ID not found.\n";
}

int main() {
    const int MAX_PERSONS = 100;
    person* people[MAX_PERSONS]; // Array of object pointers
    int total = 0;
    int choice;

    do {
        cout << "\n================ MENU ================\n";
        cout << "1. Add new Person\n";
        cout << "2. Display All Persons\n";
        cout << "3. Search by Id\n";
        cout << "4. Search by Name\n";
        cout << "5. Modify address\n";
        cout << "6. Find address by id of Person\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPerson(people, total); break;
            case 2: displayAll(people, total); break;
            case 3: searchById(people, total); break;
            case 4: searchByName(people, total); break;
            case 5: modifyAddress(people, total); break;
            case 6: findAddressById(people, total); break;
            case 7: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    // Dynamic memory cleanup
    for (int i = 0; i < total; ++i) {
        delete people[i];
    }

    return 0;
}