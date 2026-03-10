/**
 * Basic DSA - Rotate Array (LeetCode 189)
 * Rotate array to the right by k steps (in-place).
 */
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0) return;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Rotate Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    rotate(a1, 3);
    std::cout << "[1,2,3,4,5,6,7], k=3 -> [";
    for (size_t i = 0; i < a1.size(); i++) std::cout << (i ? "," : "") << a1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {-1, -100, 3, 99};
    rotate(a2, 2);
    std::cout << "[-1,-100,3,99], k=2 -> [";
    for (size_t i = 0; i < a2.size(); i++) std::cout << (i ? "," : "") << a2[i];
    std::cout << "]\n";
}
