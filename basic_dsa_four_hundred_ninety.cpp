/**
 * Basic DSA - Two Sum (LeetCode 1)
 * Exactly one pair of distinct indices with nums[i] + nums[j] == target; return {i, j}.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> indexOfValue;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        auto it = indexOfValue.find(need);
        if (it != indexOfValue.end())
            return {it->second, i};
        indexOfValue[nums[i]] = i;
    }
    return {};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum\n";
    std::cout << std::string(60, '=') << "\n";

    auto a = twoSum({2, 7, 11, 15}, 9);
    std::cout << "nums=[2,7,11,15], target=9 -> [" << a[0] << ", " << a[1] << "]\n";

    auto b = twoSum({3, 2, 4}, 6);
    std::cout << "nums=[3,2,4], target=6 -> [" << b[0] << ", " << b[1] << "]\n";
}
