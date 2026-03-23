/**
 * Basic DSA - Unique Paths (LeetCode 62)
 * Robot moves right or down from top-left to bottom-right of m x n grid.
 */
#include <iostream>
#include <string>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1];
    return dp[n - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unique Paths\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "3 x 7 -> " << uniquePaths(3, 7) << "\n";
    std::cout << "3 x 2 -> " << uniquePaths(3, 2) << "\n";
}
