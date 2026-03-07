/**
 * Basic DSA - Permutations (LeetCode 46)
 * Return all permutations of distinct integers.
 */
#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>>& ans, std::vector<int>& nums, int start) {
    if (start == (int)nums.size()) { ans.push_back(nums); return; }
    for (int i = start; i < (int)nums.size(); i++) {
        std::swap(nums[start], nums[i]);
        backtrack(ans, nums, start + 1);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    backtrack(ans, nums, 0);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Permutations\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3};
    auto r1 = permute(a1);
    std::cout << "[1,2,3] -> " << r1.size() << " permutations: ";
    for (auto& v : r1) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); i++) std::cout << (i ? "," : "") << v[i];
        std::cout << "] ";
    }
    std::cout << "\n";

    std::vector<int> a2 = {0, 1};
    auto r2 = permute(a2);
    std::cout << "[0,1] -> " << r2.size() << " permutations: ";
    for (auto& v : r2) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); i++) std::cout << (i ? "," : "") << v[i];
        std::cout << "] ";
    }
    std::cout << "\n";
}
