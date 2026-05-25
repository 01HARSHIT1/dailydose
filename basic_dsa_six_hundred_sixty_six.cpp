/**
 * Basic DSA - Find Indices With Index and Value Difference I (LeetCode 2903)
 * Find indices i, j with |i - j| >= indexDifference and |nums[i] - nums[j]| >= valueDifference.
 */
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> findIndices(const std::vector<int>& nums, int indexDifference, int valueDifference) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + indexDifference; j < n; ++j) {
            if (std::abs(nums[static_cast<size_t>(i)] - nums[static_cast<size_t>(j)]) >= valueDifference)
                return {i, j};
        }
    }
    return {-1, -1};
}

void printVec(const std::vector<int>& v) {
    std::cout << "[" << v[0] << "," << v[1] << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Indices With Index and Value Difference I\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(findIndices({5, 1, 4, 1}, 2, 4));
    printVec(findIndices({2, 1}, 0, 0));
    printVec(findIndices({1, 2, 3}, 2, 4));
}
