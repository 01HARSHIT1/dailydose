/**
 * Basic DSA - First Unique Character in a String (LeetCode 387)
 * Return index of first non-repeating char, or -1.
 */
#include <iostream>
#include <string>
#include <vector>

int firstUniqChar(std::string s) {
    std::vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    for (int i = 0; i < (int)s.size(); i++)
        if (cnt[s[i] - 'a'] == 1) return i;
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: First Unique Character in a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "leetcode -> " << firstUniqChar("leetcode") << "\n";
    std::cout << "loveleetcode -> " << firstUniqChar("loveleetcode") << "\n";
    std::cout << "aabb -> " << firstUniqChar("aabb") << "\n";
}
