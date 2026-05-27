/**
 * Basic DSA - Zero Array Transformation I (LeetCode 3355)
 * Each query decrements a range by 1; check whether nums can become all zeros.
 */
#include <iostream>
#include <vector>

bool isZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
    int n = static_cast<int>(nums.size());
    std::vector<int> diff(static_cast<size_t>(n) + 1, 0);
    for (const std::vector<int>& q : queries) {
        diff[static_cast<size_t>(q[0])]++;
        diff[static_cast<size_t>(q[1] + 1)]--;
    }

    int applied = 0;
    for (int i = 0; i < n; ++i) {
        applied += diff[static_cast<size_t>(i)];
        if (applied != nums[static_cast<size_t>(i)])
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Zero Array Transformation I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << isZeroArray({1, 0, 1}, {{0, 2}}) << "\n";
    std::cout << "sample 2 -> " << isZeroArray({4, 3, 2, 1}, {{1, 3}, {0, 2}}) << "\n";
    std::cout << "sample 3 -> " << isZeroArray({0}, {}) << "\n";
}
