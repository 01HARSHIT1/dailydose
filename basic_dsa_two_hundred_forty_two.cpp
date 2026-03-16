/**
 * Basic DSA - Squares of a Sorted Array (LeetCode 977)
 * Return squares of each element in non-decreasing order.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    for (int& x : nums) x *= x;
    std::sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Squares of a Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-4, -1, 0, 3, 10};
    sortedSquares(v1);
    std::cout << "[-4,-1,0,3,10] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {-7, -3, 2, 3, 11};
    sortedSquares(v2);
    std::cout << "[-7,-3,2,3,11] -> [";
    for (int i = 0; i < (int)v2.size(); i++) std::cout << (i ? "," : "") << v2[i];
    std::cout << "]\n";
}
