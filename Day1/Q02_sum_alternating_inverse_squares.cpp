/*
================================================================================
Question 2:
Sum of the alternating series 1/1^2 - 1/2^2 + 1/3^2 - ... until the term < 10^-6.
Print the sum to 5 decimals.

Formula / Algorithm:
- S = sum_{n=1}^inf ((-1)^(n+1) / n^2) = 1/1^2 - 1/2^2 + 1/3^2 - ...
- Magnitude of term = 1.0 / (n * n).
- Loop while magnitude >= 1e-6 (stop when magnitude < 1e-6).
- Use alternating sign factor: sign = +1 for odd n, -1 for even n.
- Theoretical limit is pi^2 / 12 approx 0.82247.

Sample Input:
(No input required; series uses fixed threshold 10^-6)

Sample Output:
Sum of alternating series = 0.82247
Total terms added = 1000
================================================================================
*/

#include <iostream>

using namespace std;

int main() {
    double sum = 0.0;
    double term_magnitude = 0.0;
    double sign = 1.0;
    long long n = 1;
    const double EPSILON = 1e-6;

    while (true) {
        term_magnitude = 1.0 / ((double)n * (double)n);
        if (term_magnitude < EPSILON) {
            break;
        }
        sum += sign * term_magnitude;
        sign = -sign; // Alternate the sign for each subsequent term
        n++;
    }

    // Set output format to fixed-point with 5 decimal places
    cout.setf(ios::fixed);
    cout.precision(5);

    cout << "Sum of alternating series = " << sum << endl;
    cout << "Total terms added = " << (n - 1) << endl;

    return 0;
}
