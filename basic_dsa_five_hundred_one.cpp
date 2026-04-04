/**
 * Basic DSA - First Unique Character in a String (LeetCode 387)
 * Return the first index whose character appears once (lowercase English letters).
 */
#include <iostream>
#include <string>

int firstUniqChar(const std::string& s) {
    int cnt[26] = {};
    for (char c : s)
        ++cnt[c - 'a'];
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (cnt[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: First Unique Character in a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"leetcode\" -> " << firstUniqChar("leetcode") << "\n";
    std::cout << "\"loveleetcode\" -> " << firstUniqChar("loveleetcode") << "\n";
    std::cout << "\"aabb\" -> " << firstUniqChar("aabb") << "\n";
}
