/*
================================================================================
Question 11:
Read n and r. Compute the binomial coefficient nCr using a hand-written
factorial function. Handle invalid input (r < 0 or r > n).

Formula / Algorithm:
- Binomial coefficient nCr = n! / (r! * (n - r)!)
- Constraints / Invalid checks:
    - n must be >= 0
    - r must satisfy 0 <= r <= n
    - If r < 0 or r > n, or n < 0, report invalid input.
- Handwritten factorial(k):
    - Computes k! iteratively: fact = 1; for i = 1 to k: fact *= i.
    - Uses long double / unsigned long long to avoid quick integer overflow.

Sample Input:
5 2

Sample Output:
Enter values for n and r: 5 2
5C2 = 10
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten factorial function
long double factorial(int k) {
    long double fact = 1.0;
    for (int i = 1; i <= k; i++) {
        fact *= (long double)i;
    }
    return fact;
}

int main() {
    int n, r;
    cout << "Enter values for n and r: ";
    if (!(cin >> n >> r)) {
        cout << "Invalid input format!" << endl;
        return 1;
    }

    // Validation checks
    if (n < 0 || r < 0 || r > n) {
        cout << "Error: Invalid input! Requires 0 <= r <= n and n >= 0." << endl;
        return 1;
    }

    long double factN = factorial(n);
    long double factR = factorial(r);
    long double factNR = factorial(n - r);

    long double nCr = factN / (factR * factNR);

    // Format output without unnecessary floating point decimals
    cout.setf(ios::fixed);
    cout.precision(0);

    cout << n << "C" << r << " = " << nCr << endl;

    return 0;
}
