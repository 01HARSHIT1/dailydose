/**
 * Basic DSA - Valid Anagram (LeetCode 242)
 * Check if two strings are anagrams.
 */
#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::vector<int> count(26, 0);
    for (size_t i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int c : count) if (c != 0) return false;
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Anagram\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "anagram, nagaram -> " << (isAnagram("anagram", "nagaram") ? "true" : "false") << "\n";
    std::cout << "rat, car -> " << (isAnagram("rat", "car") ? "true" : "false") << "\n";
    std::cout << "a, ab -> " << (isAnagram("a", "ab") ? "true" : "false") << "\n";
}
