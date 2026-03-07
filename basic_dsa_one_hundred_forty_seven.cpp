/**
 * Basic DSA - Subsets (LeetCode 78)
 * Return all possible subsets (power set) of distinct integers.
 */
#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>>& ans, std::vector<int>& cur,
               std::vector<int>& nums, int start) {
    ans.push_back(cur);
    for (int i = start; i < (int)nums.size(); i++) {
        cur.push_back(nums[i]);
        backtrack(ans, cur, nums, i + 1);
        cur.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> cur;
    backtrack(ans, cur, nums, 0);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subsets\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3};
    auto r1 = subsets(a1);
    std::cout << "[1,2,3] -> " << r1.size() << " subsets: ";
    for (auto& v : r1) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); i++) std::cout << (i ? "," : "") << v[i];
        std::cout << "] ";
    }
    std::cout << "\n";

    std::vector<int> a2 = {0};
    auto r2 = subsets(a2);
    std::cout << "[0] -> " << r2.size() << " subsets: ";
    for (auto& v : r2) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); i++) std::cout << (i ? "," : "") << v[i];
        std::cout << "] ";
    }
    std::cout << "\n";
}
