/**
 * Basic DSA - Monotonic Array (LeetCode 896)
 * Return true if array is monotonic (non-decreasing or non-increasing).
 */
#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int>& nums) {
    bool inc = true, dec = true;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] > nums[i - 1]) dec = false;
        if (nums[i] < nums[i - 1]) inc = false;
    }
    return inc || dec;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Monotonic Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 2, 3};
    std::cout << "[1,2,2,3] -> " << (isMonotonic(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {6, 5, 4, 4};
    std::cout << "[6,5,4,4] -> " << (isMonotonic(v2) ? "true" : "false") << "\n";

    std::vector<int> v3 = {1, 3, 2};
    std::cout << "[1,3,2] -> " << (isMonotonic(v3) ? "true" : "false") << "\n";
}
