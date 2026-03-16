/**
 * Basic DSA - Sort Colors (LeetCode 75)
 * Sort array of 0s, 1s, 2s in-place (Dutch National Flag).
 */
#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) {
    int lo = 0, mid = 0, hi = nums.size() - 1;
    while (mid <= hi) {
        if (nums[mid] == 0) std::swap(nums[lo++], nums[mid++]);
        else if (nums[mid] == 2) std::swap(nums[mid], nums[hi--]);
        else mid++;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort Colors\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 0, 2, 1, 1, 0};
    sortColors(v1);
    std::cout << "[2,0,2,1,1,0] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {2, 1, 0};
    sortColors(v2);
    std::cout << "[2,1,0] -> [";
    for (int i = 0; i < (int)v2.size(); i++) std::cout << (i ? "," : "") << v2[i];
    std::cout << "]\n";
}
