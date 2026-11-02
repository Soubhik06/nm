/*
================================================================================
Question 1:
Sum of the series 1/1^2 + 1/2^2 + 1/3^2 + ... until the term becomes < 10^-6.
Print the sum to 5 decimals.

Formula / Algorithm:
- S = sum_{n=1}^inf (1 / n^2)
- Compute term = 1.0 / (n * n) for n = 1, 2, 3, ...
- Loop while term >= 1e-6 (i.e. stop when term < 1e-6).
- Add each term to the running sum.
- Theoretical limit is pi^2 / 6 approx 1.64493.

Sample Input:
(No input required; series uses fixed threshold 10^-6)

Sample Output:
Sum of series = 1.64393
Total terms added = 1000
================================================================================
*/

#include <iostream>

using namespace std;

int main() {
    double sum = 0.0;
    double term = 0.0;
    long long n = 1;
    const double EPSILON = 1e-6;

    // Loop until the current term is strictly less than 10^-6
    while (true) {
        term = 1.0 / ((double)n * (double)n);
        if (term < EPSILON) {
            break;
        }
        sum += term;
        n++;
    }

    // Set output format to fixed-point with 5 decimal places
    cout.setf(ios::fixed);
    cout.precision(5);

    cout << "Sum of series = " << sum << endl;
    cout << "Total terms added = " << (n - 1) << endl;

    return 0;
}
