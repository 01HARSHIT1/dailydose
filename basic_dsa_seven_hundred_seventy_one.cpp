/**
 * Basic DSA - Minimum Operations to Make Array Sum Divisible by K (LeetCode 3512)
 * Each decrement lowers total sum by one; answer is sum modulo k.
 */

#include <iostream>
#include <vector>

int minOperations(const std::vector<int>& values, int divisor) {
    long long total = 0;

    for (const int value : values)
        total += value;

    return static_cast<int>(total % divisor);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Make Array Sum Divisible by K\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minOperations({3, 9, 7}, 5) << "\n";
    std::cout << "sample 2 -> " << minOperations({4, 1, 3}, 4) << "\n";
}
