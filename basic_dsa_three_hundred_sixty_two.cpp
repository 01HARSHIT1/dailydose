/**
 * Basic DSA - Wildcard Matching (LeetCode 44)
 * Match s to pattern p: ? any one char, * any sequence (including empty).
 */
#include <iostream>
#include <string>
#include <vector>

bool isMatch(std::string s, std::string p) {
    int m = s.size(), n = p.size();
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1));
    dp[0][0] = true;
    for (int j = 1; j <= n && p[j - 1] == '*'; j++) dp[0][j] = true;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    return dp[m][n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Wildcard Matching\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "aa, a -> " << (isMatch("aa", "a") ? "true" : "false") << "\n";
    std::cout << "aa, * -> " << (isMatch("aa", "*") ? "true" : "false") << "\n";
    std::cout << "cb, ?a -> " << (isMatch("cb", "?a") ? "true" : "false") << "\n";
}
