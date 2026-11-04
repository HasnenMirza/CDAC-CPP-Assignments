#include <iostream>
#include <cmath>
#include <algorithm> // Required for sorting in nth maximum

using namespace std;

// Maximum storage capacity of our array
const int MAX_SIZE = 100; 

// 1. Accept data into the array
void acceptData(double arr[], int &size) {
    cout << "Enter the number of elements you want to input: ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid size! Keeping it within capacity.\n";
        size = 0;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Data accepted successfully.\n";
}

// 2. Display all array data
void displayData(const double arr[], int size) {
    if (size == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}

// 3. Modify a number at a specific index/position
void modifyNumber(double arr[], int size) {
    if (size == 0) { cout << "Array is empty!\n"; return; }
    
    int pos;
    cout << "Enter the position to modify (1 to " << size << "): ";
    cin >> pos;

    // Check if position is valid
    if (pos < 1 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> arr[pos - 1]; // Convert 1-based position to 0-based index
    cout << "Position updated successfully.\n";
}

// 4. Delete the first occurrence of a specific number
void deleteNumber(double arr[], int &size) {
    if (size == 0) { cout << "Array is empty!\n"; return; }

    double target;
    cout << "Enter the number to delete: ";
    cin >> target;

    int foundIdx = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            foundIdx = i;
            break; // Stop at first match
        }
    }

    if (foundIdx == -1) {
        cout << "Number not found in the array.\n";
        return;
    }

    // Shift elements left to overwrite the deleted item
    for (int i = foundIdx; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Reduce active size tracking
    cout << "Number deleted successfully.\n";
}

// 5. Search for a number in the array
void searchNumber(const double arr[], int size) {
    if (size == 0) { cout << "Array is empty!\n"; return; }

    double target;
    cout << "Enter the number to search: ";
    cin >> target;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Found " << target << " at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Number not found in the array.\n";
}

// 6. Add all even whole numbers
void addEvenNumbers(const double arr[], int size) {
    double sum = 0;
    bool found = false;

    for (int i = 0; i < size; i++) {
        // Cast to int to check if it's a whole even number
        if (arr[i] == static_cast<int>(arr[i])) {
            int val = static_cast<int>(arr[i]);
            if (val % 2 == 0) {
                sum += arr[i];
                found = true;
            }
        }
    }
    if (found) cout << "Sum of all even whole numbers: " << sum << "\n";
    else cout << "No even whole numbers found.\n";
}

// Helper block to test prime criteria (Placed above displayPrimes)
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 7. Display only prime numbers and print count
void displayPrimes(const double arr[], int size) {
    int count = 0;
    cout << "Prime numbers in array: ";
    for (int i = 0; i < size; i++) {
        // Evaluate if value is a whole integer
        if (arr[i] == static_cast<int>(arr[i])) {
            int val = static_cast<int>(arr[i]);
            if (isPrime(val)) {
                cout << arr[i] << "  ";
                count++;
            }
        }
    }
    cout << "\nTotal Prime Count: " << count << "\n";
}

// 8. Find largest odd whole number
void findMaxOdd(const double arr[], int size) {
    double maxOdd;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == static_cast<int>(arr[i])) {
            int val = static_cast<int>(arr[i]);
            if (val % 2 != 0) {
                if (!found || arr[i] > maxOdd) {
                    maxOdd = arr[i];
                    found = true;
                }
            }
        }
    }
    if (found) cout << "Maximum odd number: " << maxOdd << "\n";
    else cout << "No odd whole numbers found.\n";
}

// 9. Find nth maximum element using temporary sorted copy
void findNthMaximum(const double arr[], int size) {
    if (size == 0) { cout << "Array is empty!\n"; return; }

    int n;
    cout << "Enter the value for N (e.g., 2 for second maximum): ";
    cin >> n;

    if (n < 1 || n > size) {
        cout << "Invalid N value!\n";
        return;
    }

    // Create a temporary array copy to keep base array unordered
    double temp[MAX_SIZE];
    for (int i = 0; i < size; i++) temp[i] = arr[i];

    // Sort copy in ascending order
    sort(temp, temp + size);

    // Grab elements from the end of sorted array
    cout << "The " << n << " maximum value is: " << temp[size - n] << "\n";
}

int main() {
    double arr[MAX_SIZE];
    int size = 0; // Tracks current number of elements
    int choice;

    do {
        // Display Operations Menu
   
        cout << "1. Accept Data\n";
        cout << "2. Display Data\n";
        cout << "3. Modify Number at a Position\n";
        cout << "4. Delete a Specific Number\n";
        cout << "5. Search a Number\n";
        cout << "6. Find Addition of All Even Numbers\n";
        cout << "7. Display Prime Numbers and Their Count\n";
        cout << "8. Find Maximum Odd Number\n";
        cout << "9. Find Nth Maximum Number\n";
        cout << "10. Exit\n";
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1: acceptData(arr, size); break;
            case 2: displayData(arr, size); break;
            case 3: modifyNumber(arr, size); break;
            case 4: deleteNumber(arr, size); break;
            case 5: searchNumber(arr, size); break;
            case 6: addEvenNumbers(arr, size); break;
            case 7: displayPrimes(arr, size); break;
            case 8: findMaxOdd(arr, size); break;
            case 9: findNthMaximum(arr, size); break;
            case 10: cout << "Exiting program. Thank you CDAC ACTS\n"; break;
            default: cout << "Invalid choice! Please choose between 1 and 10.\n";
        }
    } while (choice != 10);

    return 0;
}

