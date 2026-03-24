/**
 * Basic DSA - Distinct Subsequences (LeetCode 115)
 * Count ways t occurs as a subsequence of s.
 */
#include <iostream>
#include <string>
#include <vector>
int numDistinct(std::string s, std::string t) {
    int m = s.size(), n = t.size();
    std::vector<unsigned long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--)
            if (s[i - 1] == t[j - 1]) dp[j] += dp[j - 1];
    return (int)dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Distinct Subsequences\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "rabbbit, rabbit -> " << numDistinct("rabbbit", "rabbit") << "\n";
    std::cout << "babgbag, bag -> " << numDistinct("babgbag", "bag") << "\n";
}
