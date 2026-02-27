/**
 * Basic DSA - Fibonacci Number (LeetCode 509)
 * Return nth Fibonacci number (0-indexed).
 */
#include <iostream>

int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fibonacci Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=2 -> " << fib(2) << "\n";
    std::cout << "n=3 -> " << fib(3) << "\n";
    std::cout << "n=4 -> " << fib(4) << "\n";
    std::cout << "n=10 -> " << fib(10) << "\n";
}
