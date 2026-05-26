/**
 * Basic DSA - Existence of a Substring in a String and Its Reverse (LeetCode 3083)
 * Check whether any length-2 substring also appears in the reversed string (i.e. as a reversed adjacent pair).
 */
#include <iostream>
#include <string>
#include <unordered_set>

bool isSubstringPresent(const std::string& s) {
    std::unordered_set<std::string> pairs;
    for (size_t i = 0; i + 1 < s.size(); ++i)
        pairs.insert({s[i], s[i + 1]});
    for (const std::string& p : pairs) {
        std::string reversed = {p[1], p[0]};
        if (pairs.count(reversed))
            return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Existence of a Substring in a String and Its Reverse\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << isSubstringPresent("leetcode") << "\n";
    std::cout << "sample 2 -> " << isSubstringPresent("abcba") << "\n";
    std::cout << "sample 3 -> " << isSubstringPresent("abcd") << "\n";
}
