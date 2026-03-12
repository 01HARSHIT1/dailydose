/**
 * Basic DSA - Longest Substring Without Repeating Characters (LeetCode 3)
 * Find length of longest substring with distinct characters (sliding window).
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> seen;
    int ans = 0, lo = 0;
    for (int hi = 0; hi < (int)s.size(); hi++) {
        while (seen.count(s[hi])) seen.erase(s[lo++]);
        seen.insert(s[hi]);
        ans = std::max(ans, hi - lo + 1);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Substring Without Repeating Characters\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abcabcbb -> " << lengthOfLongestSubstring("abcabcbb") << "\n";
    std::cout << "bbbbb -> " << lengthOfLongestSubstring("bbbbb") << "\n";
    std::cout << "pwwkew -> " << lengthOfLongestSubstring("pwwkew") << "\n";
}
