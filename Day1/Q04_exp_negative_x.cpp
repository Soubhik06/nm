/*
================================================================================
Question 4:
Read x. Compute e^(-x) using the series 1 - x + x^2/2! - x^3/3! + ...
until |term| < 10^-6.

Formula / Algorithm:
- e^(-x) = sum_{n=0}^inf ((-1)^n * x^n / n!)
- First term (n=0): term = 1.0, sum = 1.0
- Subsequent terms: term_n = term_{n-1} * (-x) / n
- Handwritten absolute value function myAbs() checks |term| < 1e-6.

Sample Input:
1.0

Sample Output:
Enter value of x: 1.0
Computed e^(-x) = 0.367879
Number of terms used = 10
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten absolute value helper
double myAbs(double val) {
    return (val < 0.0) ? -val : val;
}

int main() {
    double x;
    cout << "Enter value of x: ";
    if (!(cin >> x)) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    const double EPSILON = 1e-6;

    while (true) {
        term = -term * x / (double)n;
        if (myAbs(term) < EPSILON) {
            break;
        }
        sum += term;
        n++;
    }

    // Output formatted to 6 decimal places
    cout.setf(ios::fixed);
    cout.precision(6);

    cout << "Computed e^(-" << x << ") = " << sum << endl;
    cout << "Number of terms used = " << n << endl;

    return 0;
}
