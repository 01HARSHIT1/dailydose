/**
 * Basic DSA - Count the Number of Consistent Strings (LeetCode 1684)
 * A word is consistent if every letter is in the string `allowed` (distinct chars).
 */
#include <iostream>
#include <string>
#include <vector>

int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words) {
    bool use[26] = {};
    for (unsigned char c : allowed)
        use[c - 'a'] = true;
    int ans = 0;
    for (const std::string& w : words) {
        bool ok = true;
        for (unsigned char c : w) {
            if (!use[c - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok)
            ++ans;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count the Number of Consistent Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> w1 = {"ad", "bd", "aaab", "baa", "badab"};
    std::cout << "allowed=ab, five words -> " << countConsistentStrings("ab", w1) << "\n";

    std::vector<std::string> w2 = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    std::cout << "allowed=abc -> " << countConsistentStrings("abc", w2) << "\n";
}
