/*
================================================================================
Question 3:
Value of e = 1 + 1/1! + 1/2! + 1/3! + ... until the term < 10^-6.
Print the result to 5 decimals.

Formula / Algorithm:
- e = 1 + sum_{n=1}^inf (1 / n!)
- Each successive term is computed iteratively from the previous term:
    term_0 = 1.0
    term_n = term_{n-1} / n
- Loop until term < 1e-6.
- Sum up all terms.
- Theoretical value of e approx 2.71828.

Sample Input:
(No input required; series uses fixed threshold 10^-6)

Sample Output:
Value of e = 2.71828
Total terms added = 11
================================================================================
*/

#include <iostream>

using namespace std;

int main() {
    double sum = 1.0;  // First term is 1 (for 0!)
    double term = 1.0; // Starts at 1/0!
    int n = 1;
    const double EPSILON = 1e-6;

    while (true) {
        term = term / (double)n; // term_n = term_{n-1} / n
        if (term < EPSILON) {
            break;
        }
        sum += term;
        n++;
    }

    // Set output format to fixed-point with 5 decimal places
    cout.setf(ios::fixed);
    cout.precision(5);

    cout << "Value of e = " << sum << endl;
    cout << "Total terms added = " << n << endl;

    return 0;
}
