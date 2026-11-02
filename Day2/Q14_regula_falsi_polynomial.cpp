/*
================================================================================
Question 14:
Regula Falsi (False Position): Find a root of f(x) = x^3 - x - 4 in [1, 2],
until |f(x)| < 10^-6.

Formula / Algorithm:
- Regula Falsi (False Position) formula:
    c = (a * f(b) - b * f(a)) / (f(b) - f(a))
- Check sign:
    - If f(a) * f(c) < 0, root lies in [a, c], so set b = c.
    - Otherwise, root lies in [c, b], so set a = c.
- Terminate when |f(c)| < 10^-6.
- Custom handwritten helper: myAbs(x).

Sample Input:
(No input required; interval [1, 2] is specified in question)

Sample Output:
Regula Falsi Method for f(x) = x^3 - x - 4 on [1.000000, 2.000000]
Initial check: f(a) = -4.000000, f(b) = 2.000000
f(a) * f(b) < 0 is satisfied.

Iter	a		b		c		f(c)
1	1.000000	2.000000	1.666667	-1.037037
...
Root found: 1.796322
Total iterations: 9
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Given polynomial function f(x) = x^3 - x - 4
double f(double x) {
    return x * x * x - x - 4.0;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    const double TOLERANCE = 1e-6;
    const int MAX_ITER = 100;

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Regula Falsi Method for f(x) = x^3 - x - 4 on [" << a << ", " << b << "]" << endl;

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
        // False Position formula
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
