/**
 * Basic DSA - Divisible and Non-divisible Sums Difference (LeetCode 2894)
 * Sum of 1..n not divisible by m minus sum divisible by m; compute each via arithmetic series.
 */
#include <iostream>

int differenceOfSums(int n, int m) {
    int total = n * (n + 1) / 2;
    int k = n / m;
    int divisible = m * (k * (k + 1) / 2);
    int notDivisible = total - divisible;
    return notDivisible - divisible;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Divisible and Non-divisible Sums Difference\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << differenceOfSums(10, 3) << "\n";
    std::cout << "sample 2 -> " << differenceOfSums(5, 6) << "\n";
    std::cout << "sample 3 -> " << differenceOfSums(5, 1) << "\n";
}
