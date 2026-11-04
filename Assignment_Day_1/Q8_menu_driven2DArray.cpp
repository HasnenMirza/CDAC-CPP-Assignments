#include <iostream>
#include <climits> 

using namespace std;

// Defining max capacity for the matrix rows and columns
const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// Function to take input data from the user
void acceptData(int arr[MAX_ROWS][MAX_COLS], int &rows, int &cols) {
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    // Nested loops to read each cell item
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Function to output data as a structured grid
void displayData(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t"; // Tab space between columns
        }
        cout << "\n"; // Newline after each row
    }
}

// Function to find the single largest value in matrix
void findMaximum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int maxVal = INT_MIN; // Set to lowest possible int
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j]; // Update max value
            }
        }
    }
    cout << "Maximum: " << maxVal << "\n";
}

// Function to find the single smallest value in matrix
void findMinimum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int minVal = INT_MAX; // Set to highest possible int
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j]; // Update min value
            }
        }
    }
    cout << "Minimum: " << minVal << "\n";
}

// Function to sum up all matrix values together
void findTotalSum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j]; // Add cell value to total sum
        }
    }
    cout << "Total Sum: " << sum << "\n";
}

// Function to calculate and display the sum of each individual row
void findRowSum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum tracker for every new row
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " Sum: " << rowSum << "\n";
    }
}

// Function to calculate and display the sum of each individual column
void findColumnSum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int colSum = 0; // Reset sum tracker for every new column
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Col " << j + 1 << " Sum: " << colSum << "\n";
    }
}

// Function to identify the highest number in each individual row
void findRowwiseMaximum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int maxVal = INT_MIN; // Reset max tracking value per row
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
        cout << "Row " << i + 1 << " Max: " << maxVal << "\n";
    }
}

// Function to identify the highest number in each individual column
void findColumnwiseMaximum(const int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int maxVal = INT_MIN; // Reset max tracking value per column
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
        cout << "Col " << j + 1 << " Max: " << maxVal << "\n";
    }
}

int main() {
    int arr[MAX_ROWS][MAX_COLS];
    int rows = 0; 
    int cols = 0; 
    int choice;

    // Triggers the continuous menu system
    do {
        cout << "\n1.Accept\n 2.Display\n 3.Max\n 4.Min\n 5.Sum\n 6.RowSum\n 7.ColSum\n 8.RowMax\n 9.ColMax\n 10.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Switch selection mapping to functions
        switch (choice) {
            case 1: acceptData(arr, rows, cols); break;
            case 2: displayData(arr, rows, cols); break;
            case 3: findMaximum(arr, rows, cols); break;
            case 4: findMinimum(arr, rows, cols); break;
            case 5: findTotalSum(arr, rows, cols); break;
            case 6: findRowSum(arr, rows, cols); break;
            case 7: findColumnSum(arr, rows, cols); break;
            case 8: findRowwiseMaximum(arr, rows, cols); break;
            case 9: findColumnwiseMaximum(arr, rows, cols); break;
            case 10: cout << "Exit\n"; break;
            default: cout << "Invalid\n";
        }
    } while (choice != 10); // Loop terminates when option 10 is targeted

    return 0;
}

