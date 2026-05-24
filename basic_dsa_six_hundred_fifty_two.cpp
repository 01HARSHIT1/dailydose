/**
 * Basic DSA - Sum of Squares of Special Elements (LeetCode 2778)
 * An index (1-based) is special if it divides n; sum the squares of those elements.
 */
#include <iostream>
#include <vector>

long long sumOfSquares(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            long long v = nums[static_cast<size_t>(i - 1)];
            total += v * v;
        }
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Squares of Special Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << sumOfSquares({1, 2, 3, 4}) << "\n";
    std::cout << "sample 2 -> " << sumOfSquares({2, 7, 1, 19, 18, 3}) << "\n";
}
