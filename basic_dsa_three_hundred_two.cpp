/**
 * Basic DSA - Missing Number (LeetCode 268)
 * Find the missing number in range [0..n] from array of length n.
 */
#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int x = n;
    for (int i = 0; i < n; i++) x ^= i ^ nums[i];
    return x;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Missing Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 0, 1};
    std::cout << "[3,0,1] -> " << missingNumber(v1) << "\n";

    std::vector<int> v2 = {0, 1};
    std::cout << "[0,1] -> " << missingNumber(v2) << "\n";

    std::vector<int> v3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "n=9 array -> " << missingNumber(v3) << "\n";
}
