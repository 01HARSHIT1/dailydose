/**
 * Basic DSA - Count Binary Substrings (LeetCode 696)
 * Count substrings with equal number of consecutive 0s and 1s.
 */
#include <algorithm>
#include <iostream>
#include <string>

int countBinarySubstrings(const std::string& s) {
    int prev = 0;
    int cur = 1;
    int ans = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ++cur;
        } else {
            ans += std::min(prev, cur);
            prev = cur;
            cur = 1;
        }
    }
    return ans + std::min(prev, cur);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Binary Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"00110011\" -> " << countBinarySubstrings("00110011") << "\n";
    std::cout << "\"10101\" -> " << countBinarySubstrings("10101") << "\n";
}
