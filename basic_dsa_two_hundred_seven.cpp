/**
 * Basic DSA - Subarray Sum Equals K (LeetCode 560)
 * Count subarrays that sum to k (prefix sum + hash map).
 */
#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0, ans = 0;
    for (int x : nums) {
        sum += x;
        ans += cnt[sum - k];
        cnt[sum]++;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subarray Sum Equals K\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1, 1};
    std::cout << "[1,1,1], k=2 -> " << subarraySum(a1, 2) << "\n";

    std::vector<int> a2 = {1, 2, 3};
    std::cout << "[1,2,3], k=3 -> " << subarraySum(a2, 3) << "\n";

    std::vector<int> a3 = {1, -1, 0};
    std::cout << "[1,-1,0], k=0 -> " << subarraySum(a3, 0) << "\n";
}
