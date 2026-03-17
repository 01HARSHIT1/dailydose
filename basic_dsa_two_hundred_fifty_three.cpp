/**
 * Basic DSA - Third Maximum Number (LeetCode 414)
 * Return third distinct maximum, or maximum if fewer than 3.
 */
#include <iostream>
#include <vector>
#include <set>

int thirdMax(std::vector<int>& nums) {
    std::set<int> s(nums.begin(), nums.end());
    if (s.size() < 3) return *s.rbegin();
    auto it = s.rbegin();
    std::advance(it, 2);
    return *it;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Third Maximum Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 2, 1};
    std::cout << "[3,2,1] -> " << thirdMax(v1) << "\n";

    std::vector<int> v2 = {1, 2};
    std::cout << "[1,2] -> " << thirdMax(v2) << "\n";

    std::vector<int> v3 = {2, 2, 3, 1};
    std::cout << "[2,2,3,1] -> " << thirdMax(v3) << "\n";
}
