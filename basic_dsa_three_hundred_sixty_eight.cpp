/**
 * Basic DSA - Predict the Winner (LeetCode 486)
 * Return true if player 1 can win or tie (optimal play, both add scores).
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool predictTheWinner(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) dp[i][i] = nums[i];
    for (int len = 2; len <= n; len++)
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    return dp[0][n - 1] >= 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Predict the Winner\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 5, 2};
    std::cout << "[1,5,2] -> " << (predictTheWinner(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 5, 233, 7};
    std::cout << "[1,5,233,7] -> " << (predictTheWinner(v2) ? "true" : "false") << "\n";
}
