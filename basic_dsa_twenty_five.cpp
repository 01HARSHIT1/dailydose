/**
 * Basic DSA - Longest Substring Without Repeating Characters (LeetCode 3)
 * Find length of longest substring with unique chars.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::vector<int> seen(128, 0);
    int maxLen = 0, lo = 0;
    for (size_t hi = 0; hi < s.size(); hi++) {
        seen[s[hi]]++;
        while (seen[s[hi]] > 1) {
            seen[s[lo++]]--;
        }
        maxLen = std::max(maxLen, (int)(hi - lo + 1));
    }
    return maxLen;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Substring Without Repeating Characters\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abcabcbb -> " << lengthOfLongestSubstring("abcabcbb") << "\n";
    std::cout << "bbbbb -> " << lengthOfLongestSubstring("bbbbb") << "\n";
    std::cout << "pwwkew -> " << lengthOfLongestSubstring("pwwkew") << "\n";
}
