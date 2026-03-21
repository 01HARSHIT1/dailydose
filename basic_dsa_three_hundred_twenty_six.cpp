/**
 * Basic DSA - Isomorphic Strings (LeetCode 205)
 * Return true if chars of s can be replaced to get t (one-to-one).
 */
#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, char> a2b, b2a;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i], d = t[i];
        if (a2b.count(c) && a2b[c] != d) return false;
        if (b2a.count(d) && b2a[d] != c) return false;
        a2b[c] = d;
        b2a[d] = c;
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
