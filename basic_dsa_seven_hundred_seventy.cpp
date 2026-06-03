/**
 * Basic DSA - Make a Positive Array (LeetCode 3511)
 * Greedy scan: track minimum length-3 subarray sum, replace when non-positive.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int makeArrayPositive(std::vector<int> values) {
    constexpr long long kLargeValue = 1'000'000'000'000'000'000LL;
    int operations = 0;
    long long minimumSum = static_cast<long long>(values[0]) + values[1];
    std::vector<long long> extended(values.begin(), values.end());

    for (int index = 2; index < static_cast<int>(extended.size()); ++index) {
        const long long first = extended[index - 2];
        const long long second = extended[index - 1];
        const long long third = extended[index];
        minimumSum = std::min(minimumSum + third, first + second + third);

        if (minimumSum <= 0) {
            extended[index] = kLargeValue;
            minimumSum = kLargeValue;
            ++operations;
        }
    }

    return operations;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Make a Positive Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << makeArrayPositive({-10, 15, -12}) << "\n";
    std::cout << "sample 2 -> " << makeArrayPositive({1, 2, 3}) << "\n";
}
