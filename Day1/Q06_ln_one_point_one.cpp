/*
================================================================================
Question 6:
Compute ln(1.1) using ln(1+x) = x - x^2/2 + x^3/3 - ... with x = 0.1,
until term < 10^-7.

Formula / Algorithm:
- 1 + x = 1.1 => x = 0.1
- ln(1+x) = sum_{n=1}^inf ((-1)^(n+1) * x^n / n)
- Keep power x_pow = x^n.
- term_magnitude = x_pow / n.
- Loop while term_magnitude >= 1e-7 (stop when term_magnitude < 1e-7).
- Alternate sign: + for n=1, - for n=2, etc.
- Theoretical value of ln(1.1) approx 0.0953102.

Sample Input:
(No input required; x is hard-coded to 0.1 as specified)

Sample Output:
Computed ln(1.1) = 0.0953102
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
    double sign = 1.0;
    int n = 1;

    while (true) {
        double term_magnitude = x_power / (double)n;
        if (term_magnitude < EPSILON) {
            break;
        }
        sum += sign * term_magnitude;
        sign = -sign; // Alternating signs
        n++;
        x_power *= x; // Next power of x
    }

    cout.setf(ios::fixed);
    cout.precision(7);

    cout << "Computed ln(1.1) = " << sum << endl;
    cout << "Terms computed = " << (n - 1) << endl;

    return 0;
}
