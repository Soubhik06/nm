/*
================================================================================
Question 13:
Bisection Method: Find a root of f(x) = tan(x) - tanh(x) in [3.9, 4.0],
tolerance 10^-6. Check f(a)*f(b) < 0 first.

Formula / Algorithm:
- Bisection method repeatedly halves the interval [a, b]:
    m = (a + b) / 2
- If f(a) * f(m) < 0, root lies in [a, m], so set b = m.
  Otherwise, root lies in [m, b], so set a = m.
- Terminate when (b - a)/2 < tolerance or |f(m)| < tolerance.
- Custom functions:
    - myAbs(x)
    - mySin(x), myCos(x) using Taylor series
    - myTan(x) = mySin(x) / myCos(x)
    - myExp(x) using Taylor series
    - myTanh(x) = (e^x - e^(-x)) / (e^x + e^(-x))

Sample Input:
(No input required; interval [3.9, 4.0] is specified in question)

Sample Output:
Bisection Method for f(x) = tan(x) - tanh(x) on [3.900000, 4.000000]
Initial check: f(a) = -0.051842, f(b) = 0.158498
f(a) * f(b) < 0 is satisfied.

Iter	a		b		midpoint	f(midpoint)	Error
1	3.900000	4.000000	3.950000	0.051410	0.050000
...
Root found: 3.926602
Total iterations: 17
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

// Handwritten exponential e^x
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

// Range reduction helper
double reduceAngle(double x) {
    const double PI = 3.14159265358979323846;
    const double TWO_PI = 2.0 * PI;
    long long k = (long long)(x / TWO_PI);
    x -= (double)k * TWO_PI;
    while (x > PI) x -= TWO_PI;
    while (x < -PI) x += TWO_PI;
    return x;
}

// Handwritten sin(x)
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

// Handwritten cos(x)
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

// Handwritten tan(x)
double myTan(double x) {
    return mySin(x) / myCos(x);
}

// Handwritten tanh(x) = (e^x - e^(-x)) / (e^x + e^(-x))
double myTanh(double x) {
    double ep = myExp(x);
    double em = myExp(-x);
    return (ep - em) / (ep + em);
}

// Given function f(x) = tan(x) - tanh(x)
double f(double x) {
    return myTan(x) - myTanh(x);
}

int main() {
    double a = 3.9;
    double b = 4.0;
    const double TOLERANCE = 1e-6;
    const int MAX_ITER = 100;

    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Bisection Method for f(x) = tan(x) - tanh(x) on [" << a << ", " << b << "]" << endl;

    double fa = f(a);
    double fb = f(b);

    cout << "Initial check: f(a) = " << fa << ", f(b) = " << fb << endl;

    if (fa * fb >= 0.0) {
        cout << "Error: Root is not bracketed in [" << a << ", " << b << "]. f(a)*f(b) >= 0." << endl;
        return 1;
    }
    cout << "f(a) * f(b) < 0 is satisfied.\n" << endl;

    cout << "Iter\ta\t\tb\t\tmidpoint\tf(midpoint)\tError" << endl;

    int iter = 0;
    double m = a;

    while (iter < MAX_ITER) {
        iter++;
        m = (a + b) / 2.0;
        double fm = f(m);
        double error = (b - a) / 2.0;

        cout << iter << "\t" << a << "\t" << b << "\t" << m << "\t" << fm << "\t" << error << endl;

        if (error < TOLERANCE || myAbs(fm) < TOLERANCE) {
            cout << "\nRoot found: " << m << endl;
            cout << "Total iterations: " << iter << endl;
            return 0;
        }

        if (fa * fm < 0.0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }
    }

    cout << "\nRoot found (approx): " << m << endl;
    cout << "Total iterations: " << iter << endl;

    return 0;
}
