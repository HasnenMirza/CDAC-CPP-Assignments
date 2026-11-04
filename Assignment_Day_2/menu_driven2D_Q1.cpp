
#include <iostream>
#include <climits> 
using namespace std;

// Function to accept elements into 2D array
void accept(int** arr, int rows, int cols) {
    cout << "Enter elements (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Function to display elements of 2D array
void display(int** arr, int rows, int cols) {
    cout << "2D Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Function to find max element
void FindMAX(int** arr, int row , int cols){
	int maxx = INT_MIN;
	for(int i =0; i<row; i++){
		for(int j =0; j<cols; j++){
			if(arr[i][j]>maxx){
				maxx = arr[i][j];
			}
		}
	}	
	cout<< "Maximum number in the matrix is : " << maxx<<endl;
}


//Function to find min element
void FindMin(int** arr, int row , int cols){
        int min = INT_MAX;
        for(int i =0; i<row; i++){
                for(int j =0; j<cols; j++){
                        if(arr[i][j]<min){
                                min = arr[i][j];
                        }
                }
        }
        cout<< "Minimum number in the matrix is : " << min<<endl;
}




 
//Function to sum of all element
void FindSum(int** arr, int row , int col){
        int sum = 0;
        for(int i =0; i<row; i++){
                for(int j =0; j<col; j++){
                   sum += arr[i][j];
                }
        }
        cout<< "sum of the matrix is : " << sum<<endl;
}

//Function to calculate the sum of each row
void RowSum(int** arr , int row , int col){
	int addRow[row];
	int temSum=0;
	for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
	temSum+=arr[i][j];
	}
	addRow[i]=temSum;
	temSum=0;
	}

	for(int k=0;k<row;k++){
	cout<<"Sum of "<<k+1<<" row is: " <<addRow[k]<<endl;
	}
}
//Function to calculate the sum of each coloums
void colSum(int** arr , int row , int col){
        int addCol[col];
        int temSum=0;
        for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
        temSum+=arr[j][i];
        }
        addCol[i]=temSum;
        temSum=0;
        }

        for(int k=0;k<col;k++){
        cout<<"Sum of "<<k+1<<" column is: " <<addCol[k]<<endl;
        }
}


//Function to row wies maximum
void RowMax(int** arr , int row , int col){
        int maxRow=INT_MIN;
	int max[row];
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        if(arr[i][j]>maxRow){
	maxRow=arr[i][j];
	}
	}
	max[i]=maxRow;
	maxRow=INT_MIN;
	}

	 for(int k=0;k<row;k++){
        cout<<"Maximum of "<<k+1<<" row is: " <<max[k]<<endl;
        }

}

//function to coloum wies maximum
void ColMax(int** arr, int row , int col){
   int maxCol=INT_MIN;
        int max[col];
        for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
        if(arr[j][i]>maxCol){
        maxCol=arr[j][i];
        }
        }
        max[i]=maxCol;
	maxCol=INT_MIN;
	}

         for(int k=0;k<col;k++){
        cout<<"Maximum of "<<k+1<<" coloumn is: " <<max[k]<<endl;
        }


}


int main()
{
    int rows = 3, cols = 4;
    // Dynamic allocation of 2D array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }


int choice;
    bool dataAccepted = false;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Accept data\n";
        cout << "2. Display data\n";
        cout << "3. Find maximum number\n";
        cout << "4. Find minimum number\n";
        cout << "5. Find addition of all numbers\n";
        cout << "6. Find sum of each row\n";
        cout << "7. Find sum of each column\n";
        cout << "8. Find row-wise maximum\n";
        cout << "9. Find column-wise maximum\n";
        cout << "10. Exit\n";
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        if (choice >= 2 && choice <= 9 && !dataAccepted) {
            cout << "\nPlease accept data first (Choice 1)!\n";
            continue;
        }

        switch (choice) {
            case 1:
                accept(arr, rows, cols);
                dataAccepted = true;
                break;
            case 2:
                display(arr, rows, cols);
                break;
            case 3:
                FindMAX(arr, rows, cols);
                break;
            case 4:
                FindMin(arr, rows, cols);
                break;
            case 5:
                FindSum(arr, rows, cols);
                break;
            case 6:
                RowSum(arr, rows, cols);
                break;
            case 7:
                colSum(arr, rows, cols);
                break;
            case 8:
                RowMax(arr, rows, cols);
                break;
            case 9:
                ColMax(arr, rows, cols);
                break;
            case 10:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 10.\n";
        }
    } while (choice != 10);

    
  // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;


    return 0;
}
