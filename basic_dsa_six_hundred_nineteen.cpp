/**
 * Basic DSA - Find the Array Concatenation Value (LeetCode 2562)
 * Two pointers concatenate first+last digits; single leftover element adds itself.
 */
#include <iostream>
#include <string>
#include <vector>

long long findTheArrayConcVal(std::vector<int> nums) {
    long long total = 0;
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left < right) {
        std::string joined = std::to_string(nums[static_cast<size_t>(left)]) +
                             std::to_string(nums[static_cast<size_t>(right)]);
        total += std::stoll(joined);
        ++left;
        --right;
    }
    if (left == right)
        total += nums[static_cast<size_t>(left)];
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Array Concatenation Value\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << findTheArrayConcVal({7, 52, 2, 4}) << "\n";
    std::cout << "sample 2 -> " << findTheArrayConcVal({5, 14, 13, 8, 12}) << "\n";
}
