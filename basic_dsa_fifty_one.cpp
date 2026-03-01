/**
 * Basic DSA - First Unique Character in a String (LeetCode 387)
 * Return index of first non-repeating character, or -1.
 */
#include <iostream>
#include <string>
#include <vector>

int firstUniqChar(std::string s) {
    std::vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (size_t i = 0; i < s.size(); i++)
        if (count[s[i] - 'a'] == 1) return (int)i;
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
