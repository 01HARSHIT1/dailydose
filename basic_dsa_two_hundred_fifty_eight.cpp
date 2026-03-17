/**
 * Basic DSA - Largest Perimeter Triangle (LeetCode 976)
 * Return largest perimeter of triangle from array, or 0.
 */
#include <iostream>
#include <vector>
#include <algorithm>

long long largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    long long sum = 0;
    for (int x : nums) sum += x;
    for (int i = nums.size() - 1; i >= 2; i--) {
        sum -= nums[i];
        if (sum > nums[i]) return sum + nums[i];
    }
    return 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Largest Perimeter Triangle\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 1, 2};
    std::cout << "[2,1,2] -> " << largestPerimeter(v1) << "\n";

    std::vector<int> v2 = {1, 2, 1, 10};
    std::cout << "[1,2,1,10] -> " << largestPerimeter(v2) << "\n";
}
