/**
 * Basic DSA - Count Substrings Divisible By Last Digit (LeetCode 3448)
 * Count substrings whose numeric value is divisible by their non-zero last digit.
 */

#include <iostream>
#include <string>
#include <vector>

long long countSubstrings(const std::string& s) {
    long long ans = 0;
    std::vector<std::vector<int>> dp(10, std::vector<int>(10));

    for (char ch : s) {
        const int digit = ch - '0';
        std::vector<std::vector<int>> next(10, std::vector<int>(10));

        for (int num = 1; num < 10; ++num) {
            for (int rem = 0; rem < num; ++rem)
                next[num][(rem * 10 + digit) % num] += dp[num][rem];
            ++next[num][digit % num];
        }

        dp = std::move(next);
        ans += dp[digit][0];
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Substrings Divisible By Last Digit\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countSubstrings("12936") << "\n";
    std::cout << "sample 2 -> " << countSubstrings("5701283") << "\n";
    std::cout << "sample 3 -> " << countSubstrings("1010101010") << "\n";
}
