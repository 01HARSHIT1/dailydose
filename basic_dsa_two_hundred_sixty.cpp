/**
 * Basic DSA - Maximum Average Subarray I (LeetCode 643)
 * Return maximum average of contiguous subarray of length k.
 */
#include <iostream>
#include <vector>
#include <numeric>

double findMaxAverage(std::vector<int>& nums, int k) {
    double sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
    double mx = sum;
    for (int i = k; i < (int)nums.size(); i++) {
        sum += nums[i] - nums[i - k];
        mx = std::max(mx, sum);
    }
    return mx / k;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Average Subarray I\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 12, -5, -6, 50, 3};
    std::cout << "[1,12,-5,-6,50,3], 4 -> " << findMaxAverage(v1, 4) << "\n";

    std::vector<int> v2 = {5};
    std::cout << "[5], 1 -> " << findMaxAverage(v2, 1) << "\n";
}
