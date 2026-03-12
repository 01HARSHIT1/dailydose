/**
 * Basic DSA - Minimum Size Subarray Sum (LeetCode 209)
 * Find minimal length subarray with sum >= target (sliding window).
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minSubArrayLen(int target, std::vector<int>& nums) {
    int ans = INT_MAX, sum = 0, lo = 0;
    for (int hi = 0; hi < (int)nums.size(); hi++) {
        sum += nums[hi];
        while (sum >= target) {
            ans = std::min(ans, hi - lo + 1);
            sum -= nums[lo++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Size Subarray Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 3, 1, 2, 4, 3};
    std::cout << "target=7, [2,3,1,2,4,3] -> " << minSubArrayLen(7, a1) << "\n";

    std::vector<int> a2 = {1, 4, 4};
    std::cout << "target=4, [1,4,4] -> " << minSubArrayLen(4, a2) << "\n";

    std::vector<int> a3 = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "target=11, [1,1,1,1,1,1,1,1] -> " << minSubArrayLen(11, a3) << "\n";
}
