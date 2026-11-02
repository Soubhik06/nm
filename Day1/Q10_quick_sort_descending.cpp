/*
================================================================================
Question 10:
Read n numbers and sort them in descending order using Quick Sort
(write the recursive function yourself).

Formula / Algorithm:
- Quick Sort is a divide-and-conquer algorithm.
- Partitioning:
    - Choose a pivot element (e.g. arr[high]).
    - Rearrange elements such that all elements greater than or equal to pivot
      are moved to the left of the pivot, and smaller elements to the right
      (for descending order).
- Recursively apply quick sort on the sub-arrays left and right of the pivot.
- Handwritten helper mySwap() is used for element exchange.

Sample Input:
6
14 3 77 25 90 12

Sample Output:
Enter number of elements (n): 6
Enter 6 numbers:
14 3 77 25 90 12
Sorted array (Descending Order):
90 77 25 14 12 3
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten swap helper
void mySwap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Partition function for descending order (larger elements come first)
int partitionDescending(double arr[], int low, int high) {
    double pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Condition for descending order: arr[j] >= pivot
        if (arr[j] >= pivot) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }
    mySwap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Recursive Quick Sort
void quickSortDescending(double arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDescending(arr, low, high);
        quickSortDescending(arr, low, pi - 1);
        quickSortDescending(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements (n): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    double* arr = new double[n];

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortDescending(arr, 0, n - 1);

    cout << "Sorted array (Descending Order):" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
