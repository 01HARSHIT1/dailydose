/**
 * Basic DSA - Isomorphic Strings (LeetCode 205)
 * Check if two strings are isomorphic (character mapping preserves structure).
 */
#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, char> s2t, t2s;
    for (size_t i = 0; i < s.size(); i++) {
        if (s2t.count(s[i]) && s2t[s[i]] != t[i]) return false;
        if (t2s.count(t[i]) && t2s[t[i]] != s[i]) return false;
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Isomorphic Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "egg, add -> " << (isIsomorphic("egg", "add") ? "true" : "false") << "\n";
    std::cout << "foo, bar -> " << (isIsomorphic("foo", "bar") ? "true" : "false") << "\n";
    std::cout << "paper, title -> " << (isIsomorphic("paper", "title") ? "true" : "false") << "\n";
}
