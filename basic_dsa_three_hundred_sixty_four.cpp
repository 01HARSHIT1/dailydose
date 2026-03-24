/**
 * Basic DSA - Longest Common Subsequence (LeetCode 1143)
 * Length of longest subsequence common to text1 and text2.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubsequence(std::string text1, std::string text2) {
    int m = text1.size(), n = text2.size();
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int tmp = dp[j];
            if (text1[i - 1] == text2[j - 1]) dp[j] = prev + 1;
            else dp[j] = std::max(dp[j], dp[j - 1]);
            prev = tmp;
        }
    }
    return dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Common Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abcde, ace -> " << longestCommonSubsequence("abcde", "ace") << "\n";
    std::cout << "abc, abc -> " << longestCommonSubsequence("abc", "abc") << "\n";
    std::cout << "abc, def -> " << longestCommonSubsequence("abc", "def") << "\n";
}
