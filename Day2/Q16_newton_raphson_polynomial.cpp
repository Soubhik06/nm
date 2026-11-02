/*
================================================================================
Question 16:
Newton-Raphson: Find a root of f(x) = x^4 - x - 10, starting at x0 = 2,
tolerance 10^-6. Derivative f'(x) = 4x^3 - 1.

Formula / Algorithm:
- Newton-Raphson iteration:
    x_{n+1} = x_n - f(x_n) / f'(x_n)
- Stop criterion: |x_{n+1} - x_n| < 10^-6 or |f(x_n)| < 10^-6.
- Custom handwritten helper: myAbs(x).

Sample Input:
(No input required; x0 = 2, tol = 1e-6 as specified in question)

Sample Output:
Newton-Raphson Method for f(x) = x^4 - x - 10
Initial guess x0 = 2.000000, Tolerance = 0.000001

Iter	x_n		f(x_n)		f'(x_n)		x_{n+1}		Error
1	2.000000	4.000000	31.000000	1.870968	0.129032
2	1.870968	0.382694	25.197690	1.855781	0.015187
3	1.855781	0.004812	24.574619	1.855585	0.000196
4	1.855585	0.000001	24.566632	1.855585	0.000000

Root found: 1.855585
Total iterations: 4
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Given polynomial function f(x) = x^4 - x - 10
double f(double x) {
    return x * x * x * x - x - 10.0;
}

// Derivative f'(x) = 4x^3 - 1
double fPrime(double x) {
    return 4.0 * x * x * x - 1.0;
}

int main() {
    double x = 2.0; // Starting point x0
    const double TOLERANCE = 1e-6;
    const int MAX_ITER = 100;

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Newton-Raphson Method for f(x) = x^4 - x - 10" << endl;
    cout << "Initial guess x0 = " << x << ", Tolerance = " << TOLERANCE << endl << endl;
    cout << "Iter\tx_n\t\tf(x_n)\t\tf'(x_n)\t\tx_{n+1}\t\tError" << endl;

    int iter = 0;
    while (iter < MAX_ITER) {
        iter++;
        double fx = f(x);
        double fpx = fPrime(x);

        if (myAbs(fpx) < 1e-12) {
            cout << "Error: Derivative near zero. Method fails." << endl;
            return 1;
        }

        double x_next = x - (fx / fpx);
        double error = myAbs(x_next - x);

        cout << iter << "\t" << x << "\t" << fx << "\t" << fpx << "\t" << x_next << "\t" << error << endl;

        if (error < TOLERANCE || myAbs(fx) < TOLERANCE) {
            cout << "\nRoot found: " << x_next << endl;
            cout << "Total iterations: " << iter << endl;
            return 0;
        }

        x = x_next;
    }

    cout << "Warning: Maximum iterations reached without convergence." << endl;
    return 1;
}
