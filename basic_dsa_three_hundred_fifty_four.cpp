/**
 * Basic DSA - Decode Ways (LeetCode 91)
 * Count ways to decode A=1..Z from digit string ('*' can be 1-9).
 * This version: digits only, no '*'.
 */
#include <iostream>
#include <string>
#include <vector>

int numDecodings(std::string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int one = s[i - 1] - '0';
        int two = (s[i - 2] - '0') * 10 + one;
        if (one >= 1) dp[i] += dp[i - 1];
        if (two >= 10 && two <= 26) dp[i] += dp[i - 2];
    }
    return dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Decode Ways\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "12 -> " << numDecodings("12") << "\n";
    std::cout << "226 -> " << numDecodings("226") << "\n";
    std::cout << "06 -> " << numDecodings("06") << "\n";
}
