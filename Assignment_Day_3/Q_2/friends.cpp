#include <iostream>
#include <cstring>

using namespace std;

class Friend {
private:
    int id;
    char name[50];
    
    // Dynamic arrays of pointers for multiple hobbies & mobile numbers
    char** hobbies;
    int hobbyCount;

    char** mobnos;
    int mobCount;

    char email[50];
    char bdate[15];
    char address[100];

public:
    // Default Constructor
    Friend() {
        id = 0;
        hobbies = nullptr;
        hobbyCount = 0;
        mobnos = nullptr;
        mobCount = 0;
        name[0] = '\0';
        email[0] = '\0';
        bdate[0] = '\0';
        address[0] = '\0';
    }

    // Method to accept friend details
    void acceptDetails() {
        cout << "\nEnter Friend ID: ";
        cin >> id;
        cin.ignore(); // Clear buffer

        cout << "Enter Name: ";
        cin.getline(name, 50);

        // Accept Multiple Hobbies using dynamic pointers
        cout << "How many hobbies does " << name << " have? ";
        cin >> hobbyCount;
        cin.ignore();

        if (hobbyCount > 0) {
            hobbies = new char*[hobbyCount]; // Array of char pointers
            for (int i = 0; i < hobbyCount; i++) {
                hobbies[i] = new char[50];
                cout << "  Enter Hobby " << (i + 1) << ": ";
                cin.getline(hobbies[i], 50);
            }
        }

        // Accept Multiple Mobile Numbers using dynamic pointers
        cout << "How many mobile numbers does " << name << " have? ";
        cin >> mobCount;
        cin.ignore();

        if (mobCount > 0) {
            mobnos = new char*[mobCount]; // Array of char pointers
            for (int i = 0; i < mobCount; i++) {
                mobnos[i] = new char[15];
                cout << "  Enter Mobile No " << (i + 1) << ": ";
                cin.getline(mobnos[i], 15);
            }
        }

        cout << "Enter Email: ";
        cin.getline(email, 50);

        cout << "Enter Birth Date (DD/MM/YYYY): ";
        cin.getline(bdate, 15);

        cout << "Enter Address: ";
        cin.getline(address, 100);
    }

    // Method to display friend details
    void display() const {
        cout << "\n==========================================" << endl;
        cout << "ID           : " << id << endl;
        cout << "Name         : " << name << endl;

        cout << "Hobbies      : ";
        for (int i = 0; i < hobbyCount; i++) {
            cout << hobbies[i] << (i == hobbyCount - 1 ? "" : ", ");
        }
        cout << endl;

        cout << "Mobile No(s) : ";
        for (int i = 0; i < mobCount; i++) {
            cout << mobnos[i] << (i == mobCount - 1 ? "" : ", ");
        }
        cout << endl;

        cout << "Email        : " << email << endl;
        cout << "Birth Date   : " << bdate << endl;
        cout << "Address      : " << address << endl;
        cout << "==========================================" << endl;
    }

    // Getters for searching
    int getId() const { return id; }
    const char* getName() const { return name; }

    // Helper method to check if friend has a specific hobby
    bool hasHobby(const char* targetHobby) const {
        for (int i = 0; i < hobbyCount; i++) {
            if (strcasecmp(hobbies[i], targetHobby) == 0) { // Case-insensitive compare
                return true;
            }
        }
        return false;
    }

    // Destructor to deallocate dynamic memory
    ~Friend() {
        if (hobbies != nullptr) {
            for (int i = 0; i < hobbyCount; i++) {
                delete[] hobbies[i];
            }
            delete[] hobbies;
        }

        if (mobnos != nullptr) {
            for (int i = 0; i < mobCount; i++) {
                delete[] mobnos[i];
            }
            delete[] mobnos;
        }
    }
};

int main() {
    Friend* friendsList = nullptr; // Pointer to an array of Friend objects
    int friendCount = 0;
    int choice;

    do {
        cout << "\n========== FRIEND MANAGEMENT SYSTEM ==========" << endl;
        cout << "0. Accept All Friends Details" << endl;
        cout << "1. Display All Friends" << endl;
        cout << "2. Search by ID" << endl;
        cout << "3. Search by Name" << endl;
        cout << "4. Display All Friends with a Particular Hobby" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (0-5): ";
        cin >> choice;

        switch (choice) {
        case 0: {
            // Clean up old memory if user re-enters list
            if (friendsList != nullptr) {
                delete[] friendsList;
            }

            cout << "\nHow many friends do you want to store? ";
            cin >> friendCount;

            // Allocate dynamic array of objects using pointers
            friendsList = new Friend[friendCount];

            for (int i = 0; i < friendCount; i++) {
                cout << "\n--- Enter Details for Friend " << (i + 1) << " ---";
                friendsList[i].acceptDetails();
            }
            cout << "\n--> " << friendCount << " friend(s) stored successfully!" << endl;
            break;
        }
        case 1: {
            if (friendsList == nullptr || friendCount == 0) {
                cout << "\n[!] No records found. Please enter details using Option 0." << endl;
            } else {
                cout << "\n--- Displaying All Friends (" << friendCount << ") ---" << endl;
                for (int i = 0; i < friendCount; i++) {
                    friendsList[i].display();
                }
            }
            break;
        }
        case 2: {
            if (friendsList == nullptr || friendCount == 0) {
                cout << "\n[!] No records found." << endl;
                break;
            }
            int searchId;
            bool found = false;
            cout << "\nEnter Friend ID to search: ";
            cin >> searchId;

            for (int i = 0; i < friendCount; i++) {
                if (friendsList[i].getId() == searchId) {
                    cout << "\n[+] Friend Found!";
                    friendsList[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\n[-] Friend with ID " << searchId << " not found." << endl;
            }
            break;
        }
        case 3: {
            if (friendsList == nullptr || friendCount == 0) {
                cout << "\n[!] No records found." << endl;
                break;
            }
            cin.ignore();
            char searchName[50];
            bool found = false;
            cout << "\nEnter Friend Name to search: ";
            cin.getline(searchName, 50);

            for (int i = 0; i < friendCount; i++) {
                if (strcasecmp(friendsList[i].getName(), searchName) == 0) {
                    cout << "\n[+] Friend Found!";
                    friendsList[i].display();
                    found = true;
                }
            }
            if (!found) {
                cout << "\n[-] Friend with Name '" << searchName << "' not found." << endl;
            }
            break;
        }
        case 4: {
            if (friendsList == nullptr || friendCount == 0) {
                cout << "\n[!] No records found." << endl;
                break;
            }
            cin.ignore();
            char targetHobby[50];
            bool found = false;
            cout << "\nEnter Hobby to search: ";
            cin.getline(targetHobby, 50);

            cout << "\n--- Friends with Hobby: " << targetHobby << " ---" << endl;
            for (int i = 0; i < friendCount; i++) {
                if (friendsList[i].hasHobby(targetHobby)) {
                    friendsList[i].display();
                    found = true;
                }
            }
            if (!found) {
                cout << "\n[-] No friends found with hobby '" << targetHobby << "'." << endl;
            }
            break;
        }
        case 5:
            cout << "\nExiting Program. Freeing allocated memory..." << endl;
            if (friendsList != nullptr) {
                delete[] friendsList; // Cleanup dynamic memory
            }
            break;

        default:
            cout << "\n[!] Invalid choice! Please enter a number between 0 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}