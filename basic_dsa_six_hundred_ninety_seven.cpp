/**
 * Basic DSA - Minimum Number of Operations to Make Elements in Array Distinct (LeetCode 3396)
 * Each operation removes 3 from the front; scan backward to find the last duplicate prefix.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

int minimumOperations(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
        if (!seen.insert(nums[static_cast<size_t>(i)]).second)
            return (i + 1 + 2) / 3;
    }
    return 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Number of Operations to Make Elements in Array Distinct\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumOperations({1, 2, 3, 4, 2, 3, 3, 5, 7}) << "\n";
    std::cout << "sample 2 -> " << minimumOperations({4, 5, 6, 4, 4}) << "\n";
    std::cout << "sample 3 -> " << minimumOperations({6, 7, 8, 9}) << "\n";
}
