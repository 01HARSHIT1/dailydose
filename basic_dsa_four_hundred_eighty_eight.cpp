/**
 * Basic DSA - Valid Anagram (LeetCode 242)
 * Lowercase letters only: t is an anagram of s iff multiset of letters matches.
 */
#include <iostream>
#include <string>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size())
        return false;
    int cnt[26] = {};
    for (char c : s)
        ++cnt[c - 'a'];
    for (char c : t)
        --cnt[c - 'a'];
    for (int x : cnt) {
        if (x != 0)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Anagram\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "\"anagram\", \"nagaram\" -> " << isAnagram("anagram", "nagaram") << "\n";
    std::cout << "\"rat\", \"car\" -> " << isAnagram("rat", "car") << "\n";
}
