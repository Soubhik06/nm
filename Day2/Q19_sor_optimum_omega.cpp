/*
================================================================================
Question 19:
SOR (Successive Over-Relaxation) for a 3x3 system.
Same inputs as Q18, plus starting omega, ending omega, and omega increment.
Run the method for every omega, print the iterations each needs (or "Not converged"),
and report the optimum omega with the minimum iterations.

Formula / Algorithm:
- Gauss-Seidel estimate:
    x_GS = (b_i - sum_{j < i} A_{ij} x_j^{(k+1)} - sum_{j > i} A_{ij} x_j^{(k)}) / A_{ii}
- SOR update with relaxation parameter omega:
    x_i^{(k+1)} = (1 - omega) * x_i^{(k)} + omega * x_GS
- Iterate over range [omegaStart, omegaEnd] in steps of omegaStep.
- For each omega, count iterations required to satisfy max_i |x_i^{(k+1)} - x_i^{(k)}| < tol.
- Track and report the optimum omega that minimizes the iteration count.

Sample Input:
4 1 2
1 5 1
2 1 6
16 19 25
0 0 0
0.0001 100
1.0 1.5 0.1

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
Enter omega start, omega end, and omega step:
1.0 1.5 0.1

--- SOR Iteration Results ---
Omega		Iterations
1.000000	9
1.100000	8
1.200000	9
1.300000	12
1.400000	16
1.500000	22

Optimum Omega: 1.100000 (Minimum Iterations: 8)
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Function to run SOR for a specific omega
// Returns number of iterations if converged, or -1 if not converged / diverged
int runSOR(const double a[3][3], const double b[3], const double x0[3],
           double omega, double tol, int maxIter, double finalX[3]) {
    const int N = 3;
    double x[3];
    for (int i = 0; i < N; i++) {
        x[i] = x0[i];
    }

    for (int iter = 1; iter <= maxIter; iter++) {
        double maxDiff = 0.0;

        for (int i = 0; i < N; i++) {
            double sum = b[i];
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            double xGS = sum / a[i][i];
            double xNew = (1.0 - omega) * x[i] + omega * xGS;

            // Check for divergence
            if (myAbs(xNew) > 1e12) {
                return -1;
            }

            double diff = myAbs(xNew - x[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
            x[i] = xNew;
        }

        if (maxDiff < tol) {
            for (int i = 0; i < N; i++) {
                finalX[i] = x[i];
            }
            return iter;
        }
    }

    return -1; // Max iterations reached without convergence
}

int main() {
    const int N = 3;
    double a[3][3];
    double b[3];
    double x0[3];
    double tol;
    int maxIter;
    double omegaStart, omegaEnd, omegaStep;

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
        cin >> x0[i];
    }

    cout << "Enter tolerance and maximum iterations:" << endl;
    cin >> tol >> maxIter;

    cout << "Enter omega start, omega end, and omega step:" << endl;
    cin >> omegaStart >> omegaEnd >> omegaStep;

    // Check diagonal elements
    for (int i = 0; i < N; i++) {
        if (myAbs(a[i][i]) < 1e-12) {
            cout << "Error: Diagonal element A[" << i << "][" << i << "] is zero! Method cannot proceed." << endl;
            return 1;
        }
    }

    if (omegaStep <= 0.0 || omegaStart > omegaEnd) {
        cout << "Error: Invalid omega parameters." << endl;
        return 1;
    }

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "\n--- SOR Iteration Results ---" << endl;
    cout << "Omega\t\tIterations" << endl;

    double bestOmega = -1.0;
    int minIter = 1000000000;
    double dummyX[3];

    // Loop through omega values with small tolerance for floating point loop bound
    for (double omega = omegaStart; omega <= omegaEnd + (omegaStep / 2.0); omega += omegaStep) {
        int iters = runSOR(a, b, x0, omega, tol, maxIter, dummyX);

        if (iters != -1) {
            cout << omega << "\t" << iters << endl;
            if (iters < minIter) {
                minIter = iters;
                bestOmega = omega;
            }
        } else {
            cout << omega << "\tNot converged" << endl;
        }
    }

    if (bestOmega > 0.0) {
        cout << "\nOptimum Omega: " << bestOmega << " (Minimum Iterations: " << minIter << ")" << endl;
    } else {
        cout << "\nNo omega converged within maximum iterations." << endl;
    }

    return 0;
}
