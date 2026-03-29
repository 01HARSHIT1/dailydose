/**
 * Basic DSA - Maximum Product of Two Elements in an Array (LeetCode 1464)
 * Maximize (nums[i]-1) * (nums[j]-1) for distinct indices.
 */
#include <iostream>
#include <string>
#include <vector>

int maxProduct(std::vector<int>& nums) {
    int best1 = 0;
    int best2 = 0;
    for (int x : nums) {
        if (x >= best1) {
            best2 = best1;
            best1 = x;
        } else if (x > best2) {
            best2 = x;
        }
    }
    return (best1 - 1) * (best2 - 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Product of Two Elements in an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 4, 5, 2};
    std::cout << "[3,4,5,2] -> " << maxProduct(v1) << "\n";

    std::vector<int> v2 = {1, 5, 4, 5};
    std::cout << "[1,5,4,5] -> " << maxProduct(v2) << "\n";
}
