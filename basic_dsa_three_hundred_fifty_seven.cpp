/**
 * Basic DSA - Edit Distance (LeetCode 72)
 * Min operations to convert word1 to word2 (insert/delete/replace).
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
    int m = word1.size(), n = word2.size();
    std::vector<int> dp(n + 1);
    for (int j = 0; j <= n; j++) dp[j] = j;
    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int tmp = dp[j];
            if (word1[i - 1] == word2[j - 1]) dp[j] = prev;
            else dp[j] = 1 + std::min({prev, dp[j], dp[j - 1]});
            prev = tmp;
        }
    }
    return dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Edit Distance\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "horse, ros -> " << minDistance("horse", "ros") << "\n";
    std::cout << "intention, execution -> " << minDistance("intention", "execution") << "\n";
}
