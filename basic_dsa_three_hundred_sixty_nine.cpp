/**
 * Basic DSA - Burst Balloons (LeetCode 312)
 * Max coins: burst nums[i] -> nums[i-1]*nums[i]*nums[i+1], merge neighbors.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int maxCoins(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> a(n + 2, 1);
    for (int i = 0; i < n; i++) a[i + 1] = nums[i];
    n += 2;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int len = 3; len <= n; len++)
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = std::max(dp[i][j], a[i] * a[k] * a[j] + dp[i][k] + dp[k][j]);
        }
    return dp[0][n - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Burst Balloons\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 1, 5, 8};
    std::cout << "[3,1,5,8] -> " << maxCoins(v1) << "\n";

    std::vector<int> v2 = {1, 5};
    std::cout << "[1,5] -> " << maxCoins(v2) << "\n";
}
