/**
 * Basic DSA - Climbing Stairs (LeetCode 70)
 * Distinct ways to reach step n (1 or 2 steps at a time).
 */
#include <iostream>
#include <string>

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Climbing Stairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "2 -> " << climbStairs(2) << "\n";
    std::cout << "3 -> " << climbStairs(3) << "\n";
    std::cout << "5 -> " << climbStairs(5) << "\n";
}
