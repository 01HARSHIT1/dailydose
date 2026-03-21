/**
 * Basic DSA - Two Sum (LeetCode 1)
 * Return indices i,j with nums[i]+nums[j]==target (i<j).
 */
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> idx;
    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];
        if (idx.count(need)) return {idx[need], i};
        idx[nums[i]] = i;
    }
    return {};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 7, 11, 15};
    auto r1 = twoSum(v1, 9);
    std::cout << "[2,7,11,15], 9 -> [" << r1[0] << "," << r1[1] << "]\n";

    std::vector<int> v2 = {3, 2, 4};
    auto r2 = twoSum(v2, 6);
    std::cout << "[3,2,4], 6 -> [" << r2[0] << "," << r2[1] << "]\n";

    std::vector<int> v3 = {3, 3};
    auto r3 = twoSum(v3, 6);
    std::cout << "[3,3], 6 -> [" << r3[0] << "," << r3[1] << "]\n";
}
