/**
 * Basic DSA - Climbing Stairs (LeetCode 70)
 * You can climb 1 or 2 steps per move. Count distinct ways to reach the top (n >= 1).
 * Same recurrence as Fibonacci: f(n) = f(n-1) + f(n-2). Time: O(n), Space: O(1).
 */
#include <iostream>

int climbStairs(int n) {
    if (n <= 2)
        return n;
    int a = 1;
    int b = 2;
    for (int i = 3; i <= n; ++i) {
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

    std::cout << "n=1 -> " << climbStairs(1) << "\n";
    std::cout << "n=2 -> " << climbStairs(2) << "\n";
    std::cout << "n=3 -> " << climbStairs(3) << "\n";
    std::cout << "n=5 -> " << climbStairs(5) << "\n";
}
