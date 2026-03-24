/**
 * Basic DSA - Regular Expression Matching (LeetCode 10)
 * Match s against pattern p where * means zero or more of preceding char.
 */
#include <iostream>
#include <string>
#include <vector>

bool isMatch(std::string s, std::string p) {
    int m = s.size(), n = p.size();
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1));
    dp[0][0] = true;
    for (int j = 2; j <= n; j += 2)
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
            } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    return dp[m][n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Regular Expression Matching\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "aa, a -> " << (isMatch("aa", "a") ? "true" : "false") << "\n";
    std::cout << "aa, a* -> " << (isMatch("aa", "a*") ? "true" : "false") << "\n";
    std::cout << "ab, .* -> " << (isMatch("ab", ".*") ? "true" : "false") << "\n";
}
