/**
 * Basic DSA - Longest Palindromic Subsequence (LeetCode 516)
 * Length of longest palindromic subsequence of s.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestPalindromeSubseq(std::string s) {
    int n = s.size();
    std::vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        int prev = 0;
        for (int j = i + 1; j < n; j++) {
            int tmp = dp[j];
            if (s[i] == s[j]) dp[j] = prev + 2;
            else dp[j] = std::max(dp[j], dp[j - 1]);
            prev = tmp;
        }
    }
    return dp[n - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Palindromic Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "bbbab -> " << longestPalindromeSubseq("bbbab") << "\n";
    std::cout << "cbbd -> " << longestPalindromeSubseq("cbbd") << "\n";
}
