/*
================================================================================
Question 12:
Newton-Raphson: Find a root of f(x) = cos(x) - x*e^x, starting at x0 = 0.5,
tolerance 10^-6. Derivative f'(x) = -sin(x) - e^x*(x+1).

Formula / Algorithm:
- Newton-Raphson iteration formula:
    x_{n+1} = x_n - f(x_n) / f'(x_n)
- Stop condition: |x_{n+1} - x_n| < tolerance or |f(x_n)| < tolerance.
- Custom handwritten functions:
    - myAbs(x): Absolute value.
    - myExp(x): Exponential function using Taylor series e^x = sum (x^k / k!).
    - myCos(x): Cosine function using Taylor series cos(x) = sum ((-1)^k * x^(2k) / (2k)!).
    - mySin(x): Sine function using Taylor series sin(x) = sum ((-1)^k * x^(2k+1) / (2k+1)!).

Sample Input:
(No input required; x0 = 0.5, tol = 1e-6 as specified in question)

Sample Output:
Newton-Raphson Method for f(x) = cos(x) - x*e^x
Initial guess x0 = 0.500000, Tolerance = 0.000001

Iter	x_n		f(x_n)		f'(x_n)		x_{n+1}		Error
1	0.500000	0.053222	-2.952508	0.518027	0.018027
2	0.518027	-0.000808	-3.030514	0.517757	0.000269
3	0.517757	-0.000000	-3.029340	0.517757	0.000000

Root found: 0.517757
Total iterations: 3
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Handwritten exponential e^x using Taylor series
double myExp(double x) {
    if (x < 0.0) {
        return 1.0 / myExp(-x);
    }
    double sum = 1.0;
    double term = 1.0;
    for (int k = 1; k <= 50; k++) {
        term *= x / (double)k;
        sum += term;
        if (myAbs(term) < 1e-15) break;
    }
    return sum;
}

// Range reduction helper for trigonometric series
double reduceAngle(double x) {
    const double PI = 3.14159265358979323846;
    const double TWO_PI = 2.0 * PI;
    long long k = (long long)(x / TWO_PI);
    x -= (double)k * TWO_PI;
    while (x > PI) x -= TWO_PI;
    while (x < -PI) x += TWO_PI;
    return x;
}

// Handwritten sin(x) using Taylor series
double mySin(double x) {
    x = reduceAngle(x);
    double sum = x;
    double term = x;
    for (int k = 1; k <= 30; k++) {
        term = -term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
        sum += term;
        if (myAbs(term) < 1e-15) break;
    }
    return sum;
}

// Handwritten cos(x) using Taylor series
double myCos(double x) {
    x = reduceAngle(x);
    double sum = 1.0;
    double term = 1.0;
    for (int k = 1; k <= 30; k++) {
        term = -term * x * x / ((2.0 * k - 1.0) * (2.0 * k));
        sum += term;
        if (myAbs(term) < 1e-15) break;
    }
    return sum;
}

// Given function f(x) = cos(x) - x * e^x
double f(double x) {
    return myCos(x) - x * myExp(x);
}

// Derivative f'(x) = -sin(x) - e^x * (x + 1)
double fPrime(double x) {
    return -mySin(x) - myExp(x) * (x + 1.0);
}

int main() {
    double x = 0.5; // Starting point x0
    const double TOLERANCE = 1e-6;
    const int MAX_ITER = 100;

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Newton-Raphson Method for f(x) = cos(x) - x*e^x" << endl;
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
