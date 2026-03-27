/**
 * Basic DSA - Maximize Sum Of Array After K Negations (LeetCode 1005)
 * Choose an index and change A[i] to -A[i], exactly k times; maximize sum(A).
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int largestSumAfterKNegations(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n && k > 0 && nums[i] < 0; ++i) {
        nums[i] = -nums[i];
        --k;
    }
    std::sort(nums.begin(), nums.end());
    if (k % 2 == 1)
        nums[0] = -nums[0];
    long long s = 0;
    for (int x : nums)
        s += x;
    return static_cast<int>(s);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Sum Of Array After K Negations\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {4, 2, 3};
    std::cout << "[4,2,3], k=1 -> " << largestSumAfterKNegations(v1, 1) << "\n";

    std::vector<int> v2 = {3, -1, 0, 2};
    std::cout << "[3,-1,0,2], k=3 -> " << largestSumAfterKNegations(v2, 3) << "\n";
}
