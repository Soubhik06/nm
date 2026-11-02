/*
================================================================================
Question 7:
Print the first 50 prime numbers, 5 per line.

Formula / Algorithm:
- A prime number is an integer greater than 1 with no positive divisors other than 1 and itself.
- Handwritten isPrime(n):
    - Return false if n <= 1.
    - If n == 2 or n == 3, return true.
    - If n % 2 == 0 or n % 3 == 0, return false.
    - Test divisors d from 5 upwards with step of 6 (d and d+2) while d * d <= n.
- Counter tracks primes found until 50.
- Print numbers 5 per line using tab/space separation.

Sample Input:
(No input required)

Sample Output:
First 50 Prime Numbers (5 per line):
2	3	5	7	11	
13	17	19	23	29	
31	37	41	43	47	
53	59	61	67	71	
73	79	83	89	97	
101	103	107	109	113	
127	131	137	139	149	
151	157	163	167	173	
179	181	191	193	197	
199	211	223	227	229	
================================================================================
*/

#include <iostream>

using namespace std;

// Handwritten prime checking function without <cmath>
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check factors using 6k +/- 1 rule up to d * d <= n
    for (int d = 5; (long long)d * d <= n; d += 6) {
        if (n % d == 0 || n % (d + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;

    cout << "First 50 Prime Numbers (5 per line):" << endl;

    while (count < 50) {
        if (isPrime(num)) {
            cout << num << "\t";
            count++;
            if (count % 5 == 0) {
                cout << "\n";
            }
        }
        num++;
    }

    return 0;
}
