/*
================================================================================
Question 17:
Gauss Elimination with partial pivoting for a 3x3 system.
Input the 3x4 augmented matrix, perform forward elimination with row swaps,
detect a singular matrix, and do back substitution. Print x1, x2, x3.

Formula / Algorithm:
- Augmented matrix [A | b] has dimensions 3 rows x 4 columns.
- Partial Pivoting:
    - At stage k (from k=0 to 1), locate row p (p >= k) with maximum |A[p][k]|.
    - If max |A[p][k]| < 10^-12, the matrix is singular (no unique solution).
    - If p != k, swap entire row p with row k.
- Forward Elimination:
    - Eliminate entries below pivot:
      factor = A[i][k] / A[k][k]
      A[i][j] = A[i][j] - factor * A[k][j] for j = k..3
- Back Substitution:
    - Check |A[2][2]| != 0.
    - x[2] = A[2][3] / A[2][2]
    - x[i] = (A[i][3] - sum_{j=i+1}^2 A[i][j] * x[j]) / A[i][i]

Sample Input:
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

Sample Output:
Enter 3x4 augmented matrix (row by row, 4 numbers per line):
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Handwritten swap helper
void mySwap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    const int N = 3;
    double a[3][4];

    cout << "Enter 3x4 augmented matrix (row by row, 4 numbers per line):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (!(cin >> a[i][j])) {
                cout << "Error reading matrix element!" << endl;
                return 1;
            }
        }
    }

    // Forward Elimination with Partial Pivoting
    for (int k = 0; k < N - 1; k++) {
        // Find row with largest pivot in column k
        int maxRow = k;
        double maxVal = myAbs(a[k][k]);
        for (int i = k + 1; i < N; i++) {
            if (myAbs(a[i][k]) > maxVal) {
                maxVal = myAbs(a[i][k]);
                maxRow = i;
            }
        }

        // Singularity check
        if (maxVal < 1e-12) {
            cout << "Error: Matrix is singular or nearly singular! No unique solution." << endl;
            return 1;
        }

        // Swap pivot row if needed
        if (maxRow != k) {
            for (int j = k; j <= N; j++) {
                mySwap(a[k][j], a[maxRow][j]);
            }
        }

        // Elimination
        for (int i = k + 1; i < N; i++) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j <= N; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Check last diagonal element
    if (myAbs(a[N - 1][N - 1]) < 1e-12) {
        cout << "Error: Matrix is singular! No unique solution." << endl;
        return 1;
    }

    // Back Substitution
    double x[3];
    for (int i = N - 1; i >= 0; i--) {
        double sum = a[i][N];
        for (int j = i + 1; j < N; j++) {
            sum -= a[i][j] * x[j];
        }
        x[i] = sum / a[i][i];
    }

    // Output results
    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "\nSolution:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "x" << (i + 1) << " = " << x[i] << endl;
    }

    return 0;
}
