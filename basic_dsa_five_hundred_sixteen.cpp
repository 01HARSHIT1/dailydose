/**
 * Basic DSA - Two Sum (LeetCode 1)
 * Exactly one pair of distinct indices has values summing to target. Return those indices.
 * Hash map of value -> index while scanning. Time: O(n), Space: O(n).
 */
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::pair<int, int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> idx;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        auto it = idx.find(need);
        if (it != idx.end())
            return {it->second, i};
        idx[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum\n";
    std::cout << std::string(60, '=') << "\n";

    auto p1 = twoSum({2, 7, 11, 15}, 9);
    std::cout << "nums=[2,7,11,15] target=9 -> (" << p1.first << ", " << p1.second << ")\n";

    auto p2 = twoSum({3, 2, 4}, 6);
    std::cout << "nums=[3,2,4] target=6 -> (" << p2.first << ", " << p2.second << ")\n";

    auto p3 = twoSum({3, 3}, 6);
    std::cout << "nums=[3,3] target=6 -> (" << p3.first << ", " << p3.second << ")\n";
}
