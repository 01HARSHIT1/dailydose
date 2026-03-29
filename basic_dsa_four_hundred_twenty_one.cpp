/**
 * Basic DSA - Subtract the Product and Sum of Digits of an Integer (LeetCode 1281)
 * Return (digit product) - (digit sum) for n in [1, 10^5].
 */
#include <iostream>
#include <string>

int subtractProductAndSum(int n) {
    int prod = 1;
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        prod *= d;
        sum += d;
        n /= 10;
    }
    return prod - sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subtract the Product and Sum of Digits of an Integer\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=234 -> " << subtractProductAndSum(234) << "\n";
    std::cout << "n=4421 -> " << subtractProductAndSum(4421) << "\n";
}
