/**
 * Basic DSA - N-th Tribonacci Number (LeetCode 1137)
 * T(0)=0, T(1)=T(2)=1, T(n)=T(n-1)+T(n-2)+T(n-3).
 */
#include <iostream>
#include <string>

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; i++) {
        int d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: N-th Tribonacci Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "4 -> " << tribonacci(4) << "\n";
    std::cout << "25 -> " << tribonacci(25) << "\n";
}
