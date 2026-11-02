/*
================================================================================
Question 8:
Print the first 15 Pythagorean triplets (a < b < c, a^2 + b^2 = c^2).
WARNING: The version in many notes has an infinite-loop bug because the c loop
never ends when no c exists for given (a, b). Fix it by iterating over c in
the outer loop (or bounding c) so that it strictly terminates.

Formula / Algorithm:
- Outer loop increases hypotenuse c starting from 5.
- Inner loop iterates a from 1 to c-1.
- Innermost loop iterates b from a+1 to c-1.
- Check if a^2 + b^2 == c^2.
- When a valid triplet is found, print it and increment count.
- Terminate immediately once 15 triplets are printed.

Sample Input:
(No input required)

Sample Output:
First 15 Pythagorean Triplets (a < b < c, a^2 + b^2 = c^2):
 1: (3, 4, 5) -> 3^2 + 4^2 = 9 + 16 = 25 = 5^2
 2: (6, 8, 10) -> 6^2 + 8^2 = 36 + 64 = 100 = 10^2
 3: (5, 12, 13) -> 5^2 + 12^2 = 25 + 144 = 169 = 13^2
 4: (9, 12, 15) -> 9^2 + 12^2 = 81 + 144 = 225 = 15^2
 5: (8, 15, 17) -> 8^2 + 15^2 = 64 + 225 = 289 = 17^2
 6: (12, 16, 20) -> 12^2 + 16^2 = 144 + 256 = 400 = 20^2
 7: (15, 20, 25) -> 15^2 + 20^2 = 225 + 400 = 625 = 25^2
 8: (7, 24, 25) -> 7^2 + 24^2 = 49 + 576 = 625 = 25^2
 9: (10, 24, 26) -> 10^2 + 24^2 = 100 + 576 = 676 = 26^2
10: (20, 21, 29) -> 20^2 + 21^2 = 400 + 441 = 841 = 29^2
11: (18, 24, 30) -> 18^2 + 24^2 = 324 + 576 = 900 = 30^2
12: (16, 30, 34) -> 16^2 + 30^2 = 256 + 900 = 1156 = 34^2
13: (21, 28, 35) -> 21^2 + 28^2 = 441 + 784 = 1225 = 35^2
14: (12, 35, 37) -> 12^2 + 35^2 = 144 + 1225 = 1369 = 37^2
15: (15, 36, 39) -> 15^2 + 36^2 = 225 + 1296 = 1521 = 39^2
================================================================================
*/

#include <iostream>

using namespace std;

int main() {
    int count = 0;
    const int TARGET = 15;

    cout << "First 15 Pythagorean Triplets (a < b < c, a^2 + b^2 = c^2):" << endl;

    // Iterating c in the outer loop guarantees termination with no unbounded loops
    for (int c = 5; count < TARGET; c++) {
        long long c2 = (long long)c * c;
        for (int a = 1; a < c && count < TARGET; a++) {
            long long a2 = (long long)a * a;
            for (int b = a + 1; b < c && count < TARGET; b++) {
                long long b2 = (long long)b * b;
                if (a2 + b2 == c2) {
                    count++;
                    cout << count << ": (" << a << ", " << b << ", " << c 
                         << ") -> " << a << "^2 + " << b << "^2 = " 
                         << a2 << " + " << b2 << " = " << c2 << " = " << c << "^2" << endl;
                }
            }
        }
    }

    return 0;
}
