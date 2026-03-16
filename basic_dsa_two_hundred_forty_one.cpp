/**
 * Basic DSA - Sort Array By Parity (LeetCode 905)
 * Move all even integers before odd integers.
 */
#include <iostream>
#include <vector>

std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            std::swap(nums[i], nums[j++]);
        }
    }
    return nums;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort Array By Parity\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 1, 2, 4};
    sortArrayByParity(v1);
    std::cout << "[3,1,2,4] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {0};
    sortArrayByParity(v2);
    std::cout << "[0] -> [" << v2[0] << "]\n";
}
