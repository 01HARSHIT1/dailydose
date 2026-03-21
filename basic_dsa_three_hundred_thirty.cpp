/**
 * Basic DSA - Valid Anagram (LeetCode 242)
 * Return true if t is a permutation of s.
 */
#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    for (char c : t) {
        cnt[c - 'a']--;
        if (cnt[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Anagram\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "anagram, nagaram -> " << (isAnagram("anagram", "nagaram") ? "true" : "false") << "\n";
    std::cout << "rat, car -> " << (isAnagram("rat", "car") ? "true" : "false") << "\n";
}
