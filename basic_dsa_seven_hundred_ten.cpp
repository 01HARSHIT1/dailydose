/**
 * Basic DSA - Maximum Length Substring With Two Occurrences (LeetCode 3090)
 * Sliding window: every character may appear at most twice in the substring.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maximumLengthSubstring(const std::string& s) {
    std::vector<int> count(26, 0);
    int ans = 0;

    for (int left = 0, right = 0; right < static_cast<int>(s.size()); ++right) {
        ++count[s[right] - 'a'];
        while (count[s[right] - 'a'] > 2)
            --count[s[left++] - 'a'];
        ans = std::max(ans, right - left + 1);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Length Substring With Two Occurrences\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumLengthSubstring("bcbbbcba") << "\n";
    std::cout << "sample 2 -> " << maximumLengthSubstring("aaaa") << "\n";
}
