/*
================================================================================
Question 5:
Compute ln(0.9) using ln(1-x) = -(x + x^2/2 + x^3/3 + ...) with x = 0.1,
until term < 10^-7.

Formula / Algorithm:
- 1 - x = 0.9 => x = 0.1
- ln(1-x) = - sum_{n=1}^inf (x^n / n)
- Keep power x_pow = x^n by multiplying by x each iteration.
- term = x_pow / n
- Loop while term >= 1e-7 (stop when term < 1e-7).
- Result = -sum.
- Theoretical value of ln(0.9) approx -0.1053605.

Sample Input:
(No input required; x is hard-coded to 0.1 as specified)

Sample Output:
Computed ln(0.9) = -0.1053605
Terms computed = 6
================================================================================
*/

#include <iostream>

using namespace std;

int main() {
    const double x = 0.1;
    const double EPSILON = 1e-7;

    double sum = 0.0;
    double x_power = x; // x^1
    int n = 1;

    while (true) {
        double term = x_power / (double)n;
        if (term < EPSILON) {
            break;
        }
        sum += term;
        n++;
        x_power *= x; // Next power x^(n+1)
    }

    double result = -sum;

    cout.setf(ios::fixed);
    cout.precision(7);

    cout << "Computed ln(0.9) = " << result << endl;
    cout << "Terms computed = " << (n - 1) << endl;

    return 0;
}
