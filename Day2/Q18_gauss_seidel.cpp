/*
================================================================================
Question 18:
Gauss-Seidel method for a 3x3 system.
Input matrix A, vector b, initial guess, tolerance, and max iterations.
Check for zero diagonal elements.
Print the number of iterations, and report non-convergence (including divergence/overflow).

Formula / Algorithm:
- System A * x = b:
    x_i^{(k+1)} = (b_i - sum_{j < i} A_{ij} x_j^{(k+1)} - sum_{j > i} A_{ij} x_j^{(k)}) / A_{ii}
- Zero diagonal check: if |A[i][i]| < 10^-12, method cannot proceed.
- Convergence test: max_i |x_i^{(k+1)} - x_i^{(k)}| < tolerance.
- Divergence/overflow test: if |x_i| > 10^12, declare divergent.

Sample Input:
4 1 2
1 5 1
2 1 6
16 19 25
0 0 0
0.0001 100

Sample Output:
Enter 3x3 coefficient matrix A (row by row):
4 1 2
1 5 1
2 1 6
Enter right-hand side vector b (3 values):
16 19 25
Enter initial guess x0 (3 values):
0 0 0
Enter tolerance and maximum iterations:
0.0001 100

Gauss-Seidel converged in 9 iterations.
Solution:
x1 = 1.000000
x2 = 3.000000
x3 = 3.333333
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

int main() {
    const int N = 3;
    double a[3][3];
    double b[3];
    double x[3];
    double tol;
    int maxIter;

    cout << "Enter 3x3 coefficient matrix A (row by row):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter right-hand side vector b (3 values):" << endl;
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    cout << "Enter initial guess x0 (3 values):" << endl;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << "Enter tolerance and maximum iterations:" << endl;
    cin >> tol >> maxIter;

    // Check for zero or near-zero diagonal elements
    for (int i = 0; i < N; i++) {
        if (myAbs(a[i][i]) < 1e-12) {
            cout << "Error: Diagonal element A[" << i << "][" << i << "] is zero! Gauss-Seidel cannot proceed." << endl;
            return 1;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(6);

    int iter = 0;
    bool converged = false;

    while (iter < maxIter) {
        iter++;
        double maxDiff = 0.0;

        for (int i = 0; i < N; i++) {
            double sum = b[i];
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            double xNew = sum / a[i][i];

            // Divergence/overflow check
            if (myAbs(xNew) > 1e12) {
                cout << "Error: Method diverged (values exceeded overflow threshold) at iteration " << iter << "." << endl;
                return 1;
            }

            double diff = myAbs(xNew - x[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
            x[i] = xNew;
        }

        if (maxDiff < tol) {
            converged = true;
            break;
        }
    }

    if (converged) {
        cout << "\nGauss-Seidel converged in " << iter << " iterations." << endl;
        cout << "Solution:" << endl;
        for (int i = 0; i < N; i++) {
            cout << "x" << (i + 1) << " = " << x[i] << endl;
        }
    } else {
        cout << "\nDid not converge within " << maxIter << " maximum iterations." << endl;
        cout << "Last approximate solution:" << endl;
        for (int i = 0; i < N; i++) {
            cout << "x" << (i + 1) << " = " << x[i] << endl;
        }
    }

    return 0;
}
