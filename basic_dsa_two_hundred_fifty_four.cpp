/**
 * Basic DSA - Find All Numbers Disappeared in an Array (LeetCode 448)
 * Return numbers in [1,n] not present in nums.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    std::vector<int> ans;
    for (int i = 1; i <= (int)nums.size(); i++)
        if (!s.count(i)) ans.push_back(i);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find All Numbers Disappeared in an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {4, 3, 2, 7, 8, 2, 3, 1};
    auto r1 = findDisappearedNumbers(v1);
    std::cout << "[4,3,2,7,8,2,3,1] -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {1, 1};
    auto r2 = findDisappearedNumbers(v2);
    std::cout << "[1,1] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
