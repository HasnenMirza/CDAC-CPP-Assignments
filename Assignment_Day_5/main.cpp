#include <iostream>
#include "Account.h"
#include "Saving.h"
#include "curr.h"
#include "demat.h"

using namespace std;

const int MAX_ACCOUNTS = 50;

int findAccount(Account* bank[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (bank[i]->getAccId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    Account* bank[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    do {
        cout << "\n===== XYZ BANK SYSTEM =====" << endl;
        cout << "1. Add new account" << endl;
        cout << "2. Display account details by id" << endl;
        cout << "3. Close account" << endl;
        cout << "4. Count a type of account" << endl;
        cout << "5. Withdraw amount" << endl;
        cout << "6. Deposit amount" << endl;
        cout << "7. Change pin" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (totalAccounts >= MAX_ACCOUNTS) {
                cout << "Bank account limit reached!" << endl;
                break;
            }
            int type;
            cout << "Select Type (1: Saving, 2: Current, 3: Demat): ";
            cin >> type;

            Account* newAcc = nullptr;
            if (type == 1) newAcc = new Saving();
            else if (type == 2) newAcc = new Current();
            else if (type == 3) newAcc = new Demat();
            else {
                cout << "Invalid type!" << endl;
                break;
            }

            newAcc->createAcc();
            bank[totalAccounts++] = newAcc;
            cout << "Account created successfully! ID: " << newAcc->getAccId() << endl;
            break;
        }
        case 2: {
            int id;
            cout << "Enter Account ID: ";
            cin >> id;
            int idx = findAccount(bank, totalAccounts, id);
            if (idx != -1) {
                bank[idx]->displayAcc();
            } else {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 3: {
            int id;
            cout << "Enter Account ID to Close: ";
            cin >> id;
            int idx = findAccount(bank, totalAccounts, id);
            if (idx != -1) {
                delete bank[idx];
                for (int i = idx; i < totalAccounts - 1; i++) {
                    bank[i] = bank[i + 1];
                }
                totalAccounts--;
                cout << "Account closed successfully!" << endl;
            } else {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 4: {
            int type;
            cout << "Enter type to count (1: Saving, 2: Current, 3: Demat): ";
            cin >> type;
            if (type == 1) cout << "Total Saving Accounts: " << Saving::getSavingCount() << endl;
            else if (type == 2) cout << "Total Current Accounts: " << Current::getCurrentCount() << endl;
            else if (type == 3) cout << "Total Demat Accounts: " << Demat::getDematCount() << endl;
            else cout << "Invalid Account Type!" << endl;
            break;
        }
        case 5: {
            int id, p;
            double amt;
            cout << "Enter Account ID: ";
            cin >> id;
            int idx = findAccount(bank, totalAccounts, id);
            if (idx != -1) {
                cout << "Enter PIN: ";
                cin >> p;
                if (bank[idx]->verifyPin(p)) {
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amt;
                    bank[idx]->withdraw(amt);
                } else {
                    cout << "Incorrect PIN!" << endl;
                }
            } else {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 6: {
            int id;
            double amt;
            cout << "Enter Account ID: ";
            cin >> id;
            int idx = findAccount(bank, totalAccounts, id);
            if (idx != -1) {
                cout << "Enter Amount to Deposit: ";
                cin >> amt;
                bank[idx]->deposit(amt);
            } else {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 7: {
            int id, oldPin, newPin;
            cout << "Enter Account ID: ";
            cin >> id;
            int idx = findAccount(bank, totalAccounts, id);
            if (idx != -1) {
                cout << "Enter Current PIN: ";
                cin >> oldPin;
                if (bank[idx]->verifyPin(oldPin)) {
                    cout << "Enter New PIN: ";
                    cin >> newPin;
                    bank[idx]->setPin(newPin);
                    cout << "PIN updated successfully!" << endl;
                } else {
                    cout << "Incorrect PIN!" << endl;
                }
            } else {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < totalAccounts; i++) {
        delete bank[i];
    }

    return 0;
}