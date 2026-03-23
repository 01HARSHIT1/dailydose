/**
 * Basic DSA - Fibonacci Number (LeetCode 509)
 * F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2).
 */
#include <iostream>
#include <string>

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

    std::cout << "2 -> " << fib(2) << "\n";
    std::cout << "3 -> " << fib(3) << "\n";
    std::cout << "4 -> " << fib(4) << "\n";
}
