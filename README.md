# Numerical Methods & C++ Exam Prep Repository

This repository contains single-file, self-contained C++ solutions for exam preparation. Every program strictly adheres to the following rules:
- **Header restriction**: Only `#include <iostream>` is used (no `<cmath>`, `<vector>`, `<algorithm>`, `<iomanip>`, etc.).
- **Self-contained**: All mathematical and utility functions (`myAbs`, `myExp`, `mySin`, `myCos`, `myTan`, `myTanh`, `mySwap`, `factorial`, etc.) are written by hand from scratch using Taylor series or standard algorithms.
- **Portability**: Each `.cpp` file can be directly copied and pasted into [OnlineGDB](https://www.onlinegdb.com/) or any C++11/C++14/C++17/C++20 compliant compiler.

---

## Question Index

### Day 1: Series, Algorithms & Number Theory

| Question | Title | Source File | Description / Algorithm |
| :--- | :--- | :--- | :--- |
| **Q01** | Sum of Inverse Squares | [`Day1/Q01_sum_inverse_squares.cpp`](Day1/Q01_sum_inverse_squares.cpp) | $\sum \frac{1}{n^2}$ until term $< 10^{-6}$ (5 decimals) |
| **Q02** | Alternating Inverse Squares | [`Day1/Q02_sum_alternating_inverse_squares.cpp`](Day1/Q02_sum_alternating_inverse_squares.cpp) | $\sum \frac{(-1)^{n+1}}{n^2}$ until term $< 10^{-6}$ (5 decimals) |
| **Q03** | Value of Euler's Number $e$ | [`Day1/Q03_value_of_e.cpp`](Day1/Q03_value_of_e.cpp) | $1 + \sum \frac{1}{n!}$ until term $< 10^{-6}$ (5 decimals) |
| **Q04** | Value of $e^{-x}$ Series | [`Day1/Q04_exp_negative_x.cpp`](Day1/Q04_exp_negative_x.cpp) | $\sum \frac{(-x)^n}{n!}$ until $\lvert\text{term}\rvert < 10^{-6}$ |
| **Q05** | Compute $\ln(0.9)$ | [`Day1/Q05_ln_point_nine.cpp`](Day1/Q05_ln_point_nine.cpp) | $-\sum \frac{x^n}{n}$ with $x = 0.1$ until term $< 10^{-7}$ |
| **Q06** | Compute $\ln(1.1)$ | [`Day1/Q06_ln_one_point_one.cpp`](Day1/Q06_ln_one_point_one.cpp) | $\sum \frac{(-1)^{n+1} x^n}{n}$ with $x = 0.1$ until term $< 10^{-7}$ |
| **Q07** | First 50 Prime Numbers | [`Day1/Q07_first_50_primes.cpp`](Day1/Q07_first_50_primes.cpp) | Trial division ($6k \pm 1$ test), printed 5 numbers per line |
| **Q08** | First 15 Pythagorean Triplets | [`Day1/Q08_pythagorean_triplets.cpp`](Day1/Q08_pythagorean_triplets.cpp) | Iterating over hypotenuse $c$ with guaranteed termination |
| **Q09** | Bubble Sort (Ascending) | [`Day1/Q09_bubble_sort_ascending.cpp`](Day1/Q09_bubble_sort_ascending.cpp) | Reads $n$ numbers, sorts ascending with handwritten swap |
| **Q10** | Quick Sort (Descending) | [`Day1/Q10_quick_sort_descending.cpp`](Day1/Q10_quick_sort_descending.cpp) | Recursive quick sort with custom partition for descending order |
| **Q11** | Binomial Coefficient $^nC_r$ | [`Day1/Q11_binomial_nCr.cpp`](Day1/Q11_binomial_nCr.cpp) | Handwritten factorial with strict input validation ($0 \le r \le n$) |

---

### Day 2: Numerical Methods & Linear Algebra

| Question | Title | Source File | Description / Algorithm |
| :--- | :--- | :--- | :--- |
| **Q12** | Newton-Raphson (Transcendental) | [`Day2/Q12_newton_raphson_transcendental.cpp`](Day2/Q12_newton_raphson_transcendental.cpp) | Root of $f(x) = \cos(x) - x e^x$ using custom $\cos, \sin, \exp$ |
| **Q13** | Bisection Method ($\tan - \tanh$) | [`Day2/Q13_bisection_tan_tanh.cpp`](Day2/Q13_bisection_tan_tanh.cpp) | Root of $f(x) = \tan(x) - \tanh(x)$ in $[3.9, 4.0]$ |
| **Q14** | Regula Falsi (Polynomial) | [`Day2/Q14_regula_falsi_polynomial.cpp`](Day2/Q14_regula_falsi_polynomial.cpp) | Root of $f(x) = x^3 - x - 4$ in $[1, 2]$ |
| **Q15** | Regula Falsi (Exponential) | [`Day2/Q15_regula_falsi_exp.cpp`](Day2/Q15_regula_falsi_exp.cpp) | Root of $f(x) = x - e^{-x}$ in $[0, 1]$ |
| **Q16** | Newton-Raphson (Polynomial) | [`Day2/Q16_newton_raphson_polynomial.cpp`](Day2/Q16_newton_raphson_polynomial.cpp) | Root of $f(x) = x^4 - x - 10$ starting at $x_0 = 2$ |
| **Q17** | Gauss Elimination with Partial Pivoting | [`Day2/Q17_gauss_elimination_partial_pivoting.cpp`](Day2/Q17_gauss_elimination_partial_pivoting.cpp) | $3 \times 3$ system, partial pivoting, singularity check, back substitution |
| **Q18** | Gauss-Seidel Method | [`Day2/Q18_gauss_seidel.cpp`](Day2/Q18_gauss_seidel.cpp) | Iterative solver for $3 \times 3$ system with zero diagonal & divergence checks |
| **Q19** | SOR Method & Optimum $\omega$ | [`Day2/Q19_sor_optimum_omega.cpp`](Day2/Q19_sor_optimum_omega.cpp) | Successive Over-Relaxation across $\omega$ range to find minimum iterations |

---

## Compilation Instructions

To compile any file locally using `g++` with all warnings enabled:
```bash
g++ -Wall -Wextra Day1/Q01_sum_inverse_squares.cpp -o Q01
./Q01
```
All files strictly require only `#include <iostream>` and no external linking libraries.
