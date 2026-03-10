/**
 * Basic DSA - Move Zeroes (LeetCode 283)
 * Move all 0s to end while maintaining relative order of non-zero elements.
 */
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[j++], nums[i]);
        }
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Move Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {0, 1, 0, 3, 12};
    moveZeroes(a1);
    std::cout << "[0,1,0,3,12] -> [";
    for (size_t i = 0; i < a1.size(); i++) std::cout << (i ? "," : "") << a1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {0};
    moveZeroes(a2);
    std::cout << "[0] -> [0]\n";

    std::vector<int> a3 = {1, 0, 2, 0, 3};
    moveZeroes(a3);
    std::cout << "[1,0,2,0,3] -> [";
    for (size_t i = 0; i < a3.size(); i++) std::cout << (i ? "," : "") << a3[i];
    std::cout << "]\n";
}
