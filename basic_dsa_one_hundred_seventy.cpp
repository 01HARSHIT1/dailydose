/**
 * Basic DSA - Squares of a Sorted Array (LeetCode 977)
 * Return squares of each element in non-decreasing order.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> out(nums.size());
    int i = 0, j = (int)nums.size() - 1, k = j;
    while (i <= j) {
        int a = nums[i] * nums[i], b = nums[j] * nums[j];
        if (a >= b) { out[k--] = a; i++; }
        else { out[k--] = b; j--; }
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Squares of a Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-4, -1, 0, 3, 10};
    auto r1 = sortedSquares(a1);
    std::cout << "[-4,-1,0,3,10] -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {-7, -3, 2, 3, 11};
    auto r2 = sortedSquares(a2);
    std::cout << "[-7,-3,2,3,11] -> [";
    for (size_t i = 0; i < r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
