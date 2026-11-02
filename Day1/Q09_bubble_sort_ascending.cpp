/*
================================================================================
Question 9:
Read n numbers and sort them in ascending order using Bubble Sort.

Formula / Algorithm:
- Bubble Sort repeatedly steps through the list, compares adjacent elements,
  and swaps them if they are in the wrong order (arr[j] > arr[j+1]).
- An early-exit flag 'swapped' stops execution if a pass makes no swaps (O(n) best case).
- Handwritten helper mySwap() is used for element exchange.

Sample Input:
6
45 12 89 23 7 34

Sample Output:
Enter number of elements (n): 6
Enter 6 numbers:
45 12 89 23 7 34
Sorted array (Ascending Order):
7 12 23 34 45 89
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten swap function
void mySwap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Bubble sort algorithm for ascending order
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, array is sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements (n): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Dynamic allocation without external containers
    double* arr = new double[n];

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array (Ascending Order):" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
