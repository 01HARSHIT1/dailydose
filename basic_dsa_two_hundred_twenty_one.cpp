/**
 * Basic DSA - Pow(x, n) (LeetCode 50)
 * Compute x raised to power n (binary exponentiation).
 */
#include <iostream>

double myPow(double x, int n) {
    if (n == 0) return 1;
    long long exp = n;
    if (exp < 0) { x = 1 / x; exp = -exp; }
    double ans = 1;
    while (exp) {
        if (exp & 1) ans *= x;
        x *= x;
        exp >>= 1;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Pow(x, n)\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "2.0^10 -> " << myPow(2.0, 10) << "\n";
    std::cout << "2.1^3 -> " << myPow(2.1, 3) << "\n";
    std::cout << "2.0^-2 -> " << myPow(2.0, -2) << "\n";
}
