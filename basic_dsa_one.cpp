/**
 * Basic DSA - Two Sum (LeetCode 1)
 * Return indices of two numbers that add up to target.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need))
            return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 7, 11, 15};
    auto r1 = twoSum(a1, 9);
    std::cout << "[2,7,11,15], target=9 -> [" << r1[0] << "," << r1[1] << "]\n";

    std::vector<int> a2 = {3, 2, 4};
    auto r2 = twoSum(a2, 6);
    std::cout << "[3,2,4], target=6 -> [" << r2[0] << "," << r2[1] << "]\n";
}
