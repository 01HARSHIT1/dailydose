/**
 * Basic DSA - Stone Game (LeetCode 877)
 * Alice first; optimal play; true if Alice ends with more stones.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool stoneGame(std::vector<int>& piles) {
    int n = piles.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) dp[i][i] = piles[i];
    for (int len = 2; len <= n; len++)
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = std::max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
    return dp[0][n - 1] > 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Stone Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> p = {5, 3, 4, 5};
    std::cout << "[5,3,4,5] Alice wins -> " << (stoneGame(p) ? "true" : "false") << "\n";
}
