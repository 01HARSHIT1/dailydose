/**
 * Basic DSA - Buddy Strings (LeetCode 859)
 * True if swapping two characters in s yields t (same length).
 */
#include <iostream>
#include <string>
#include <vector>

bool buddyStrings(const std::string& s, const std::string& t) {
    if (s.size() != t.size())
        return false;
    if (s == t) {
        std::vector<int> cnt(26);
        for (unsigned char c : s) {
            if (++cnt[c - 'a'] > 1)
                return true;
        }
        return false;
    }
    int i = -1, j = -1;
    for (size_t k = 0; k < s.size(); ++k) {
        if (s[k] != t[k]) {
            if (i < 0)
                i = static_cast<int>(k);
            else if (j < 0)
                j = static_cast<int>(k);
            else
                return false;
        }
    }
    return j >= 0 && s[static_cast<size_t>(i)] == t[static_cast<size_t>(j)] && s[static_cast<size_t>(j)] == t[static_cast<size_t>(i)];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Buddy Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "s=ab, t=ba -> " << (buddyStrings("ab", "ba") ? "true" : "false") << "\n";
    std::cout << "s=ab, t=ab -> " << (buddyStrings("ab", "ab") ? "true" : "false") << "\n";
    std::cout << "s=aa, t=aa -> " << (buddyStrings("aa", "aa") ? "true" : "false") << "\n";
}
