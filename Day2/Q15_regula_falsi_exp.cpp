/*
================================================================================
Question 15:
Regula Falsi (False Position): Find a root of f(x) = x - e^(-x) in [0, 1],
until |f(x)| < 10^-6.

Formula / Algorithm:
- Regula Falsi formula:
    c = (a * f(b) - b * f(a)) / (f(b) - f(a))
- If f(a) * f(c) < 0, root is in [a, c], set b = c.
  Otherwise, root is in [c, b], set a = c.
- Terminate when |f(c)| < 10^-6.
- Custom handwritten functions:
    - myAbs(x)
    - myExp(x) using Taylor series e^x = sum (x^k / k!)

Sample Input:
(No input required; interval [0, 1] is specified in question)

Sample Output:
Regula Falsi Method for f(x) = x - e^(-x) on [0.000000, 1.000000]
Initial check: f(a) = -1.000000, f(b) = 0.632121
f(a) * f(b) < 0 is satisfied.

Iter	a		b		c		f(c)
1	0.000000	1.000000	0.612700	0.070814
...
Root found: 0.567143
Value of f(root): -0.000000
Total iterations: 9
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Handwritten exponential helper e^x
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

// Given function f(x) = x - e^(-x)
double f(double x) {
    return x - myExp(-x);
}

int main() {
    double a = 0.0;
    double b = 1.0;
    const double TOLERANCE = 1e-6;
    const int MAX_ITER = 100;

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Regula Falsi Method for f(x) = x - e^(-x) on [" << a << ", " << b << "]" << endl;

    double fa = f(a);
    double fb = f(b);

    cout << "Initial check: f(a) = " << fa << ", f(b) = " << fb << endl;

    if (fa * fb >= 0.0) {
        cout << "Error: Root is not bracketed in [" << a << ", " << b << "]." << endl;
        return 1;
    }
    cout << "f(a) * f(b) < 0 is satisfied.\n" << endl;

    cout << "Iter\ta\t\tb\t\tc\t\tf(c)" << endl;

    int iter = 0;
    double c = a;

    while (iter < MAX_ITER) {
        iter++;
        c = (a * fb - b * fa) / (fb - fa);
        double fc = f(c);

        cout << iter << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        if (myAbs(fc) < TOLERANCE) {
            cout << "\nRoot found: " << c << endl;
            cout << "Value of f(root): " << fc << endl;
            cout << "Total iterations: " << iter << endl;
            return 0;
        }

        if (fa * fc < 0.0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    cout << "\nRoot found (approx): " << c << endl;
    cout << "Total iterations: " << iter << endl;

    return 0;
}
