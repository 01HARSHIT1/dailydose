/**
 * Basic DSA - Move Zeroes (LeetCode 283)
 * Move all 0's to the end while maintaining relative order.
 */
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != 0) std::swap(nums[k++], nums[i]);
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Move Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {0, 1, 0, 3, 12};
    moveZeroes(v1);
    std::cout << "[0,1,0,3,12] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {0};
    moveZeroes(v2);
    std::cout << "[0] -> [" << v2[0] << "]\n";
}
