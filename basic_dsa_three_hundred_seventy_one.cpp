/**
 * Basic DSA - Subarray Sum Equals K (LeetCode 560)
 * Count contiguous subarrays with sum k.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<long long, int> cnt;
    cnt[0] = 1;
    long long pre = 0;
    int ans = 0;
    for (int x : nums) {
        pre += x;
        ans += cnt[pre - k];
        cnt[pre]++;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subarray Sum Equals K\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 1};
    std::cout << "[1,1,1], k=2 -> " << subarraySum(v1, 2) << "\n";

    std::vector<int> v2 = {1, 2, 3};
    std::cout << "[1,2,3], k=3 -> " << subarraySum(v2, 3) << "\n";
}
