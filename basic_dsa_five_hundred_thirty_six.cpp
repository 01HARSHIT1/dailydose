/**
 * Basic DSA - Integer Break (LeetCode 343)
 * Split n >= 2 into integers >= 2 so their product is maximized. Greedy: factor out 3s while n > 4.
 */
#include <iostream>

int integerBreak(int n) {
    if (n <= 3) return n - 1;
    int prod = 1;
    while (n > 4) {
        prod *= 3;
        n -= 3;
    }
    return prod * n;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Integer Break\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=2  -> " << integerBreak(2) << "\n";
    std::cout << "n=3  -> " << integerBreak(3) << "\n";
    std::cout << "n=4  -> " << integerBreak(4) << "\n";
    std::cout << "n=10 -> " << integerBreak(10) << "\n";
}
