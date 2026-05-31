/**
 * Basic DSA - Longest Palindromic Subsequence After at Most K Operations (LeetCode 3472)
 * Maximize LPS length after changing chars with wrap-around alphabet, at most k ops.
 */

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int charCost(char a, char b) {
    const int dist = std::abs(a - b);
    return std::min(dist, 26 - dist);
}

int longestPalindromicSubsequence(const std::string& s, int k) {
    const int n = static_cast<int>(s.size());
    std::vector<std::vector<std::vector<int>>> memo(
        n, std::vector<std::vector<int>>(n, std::vector<int>(k + 1, -1)));

    std::function<int(int, int, int)> dfs = [&](int i, int j, int ops) -> int {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (memo[i][j][ops] != -1)
            return memo[i][j][ops];

        int result = std::max(dfs(i + 1, j, ops), dfs(i, j - 1, ops));
        const int cost = charCost(s[i], s[j]);
        if (cost <= ops)
            result = std::max(result, 2 + dfs(i + 1, j - 1, ops - cost));

        return memo[i][j][ops] = result;
    };

    return dfs(0, n - 1, k);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Palindromic Subsequence After at Most K Operations\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << longestPalindromicSubsequence("abced", 2) << "\n";
    std::cout << "sample 2 -> " << longestPalindromicSubsequence("aaazzz", 4) << "\n";
}
