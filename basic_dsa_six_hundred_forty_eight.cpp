/**
 * Basic DSA - Find the Distinct Difference Array (LeetCode 2670)
 * diff[i] = distinct prefix count (0..i) minus distinct suffix count (i+1..n-1); precompute suffix sets.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> distinctDifferenceArray(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> suffix(static_cast<size_t>(n) + 1, 0);
    std::unordered_set<int> seen;
    for (int i = n - 1; i >= 0; --i) {
        seen.insert(nums[static_cast<size_t>(i)]);
        suffix[static_cast<size_t>(i)] = static_cast<int>(seen.size());
    }

    std::vector<int> result(static_cast<size_t>(n), 0);
    std::unordered_set<int> prefix;
    for (int i = 0; i < n; ++i) {
        prefix.insert(nums[static_cast<size_t>(i)]);
        result[static_cast<size_t>(i)] =
            static_cast<int>(prefix.size()) - suffix[static_cast<size_t>(i + 1)];
    }
    return result;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Distinct Difference Array\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(distinctDifferenceArray({1, 2, 3, 4, 5}));
    printVec(distinctDifferenceArray({3, 2, 3, 4, 2}));
}
