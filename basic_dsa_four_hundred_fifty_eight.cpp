/**
 * Basic DSA - Largest Positive Integer That Exists With Its Negative (LeetCode 2441)
 * Return the largest x > 0 such that -x is also in nums, or -1 if none.
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int findMaxK(std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int ans = -1;
    for (int x : nums) {
        if (x > 0 && s.count(-x))
            ans = std::max(ans, x);
    }
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Largest Positive Integer That Exists With Its Negative\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, 2, -3, 3};
    printVec(a1);
    std::cout << " -> " << findMaxK(a1) << "\n";

    std::vector<int> a2 = {-1, 10, 6, 7, -7};
    printVec(a2);
    std::cout << " -> " << findMaxK(a2) << "\n";

    std::vector<int> a3 = {1, 3, 4, 5};
    printVec(a3);
    std::cout << " -> " << findMaxK(a3) << "\n";
}
