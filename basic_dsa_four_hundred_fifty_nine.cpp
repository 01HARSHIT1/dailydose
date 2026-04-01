/**
 * Basic DSA - Count Pairs Whose Sum is Less than Target (LeetCode 2824)
 * Count pairs (i, j) with i < j and nums[i] + nums[j] < target.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int countPairs(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ans = 0;
    int i = 0, j = static_cast<int>(nums.size()) - 1;
    while (i < j) {
        if (nums[i] + nums[j] < target) {
            ans += j - i;
            ++i;
        } else {
            --j;
        }
    }
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t k = 0; k < v.size(); ++k) {
        if (k)
            std::cout << ", ";
        std::cout << v[k];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Pairs Whose Sum is Less than Target\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, 1, 2, 3, 1};
    printVec(a1);
    std::cout << ", target=2 -> " << countPairs(a1, 2) << "\n";

    std::vector<int> a2 = {-6, 2, 5, -2, 0, 4, 5, 0};
    printVec(a2);
    std::cout << ", target=2 -> " << countPairs(a2, 2) << "\n";
}
