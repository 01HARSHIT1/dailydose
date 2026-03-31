/**
 * Basic DSA - First Letter to Appear Twice (LeetCode 2351)
 * Given a string of lowercase English letters, return the first character seen twice.
 */
#include <iostream>
#include <string>

char repeatedCharacter(const std::string& s) {
    int seen[26] = {};
    for (char c : s) {
        int i = c - 'a';
        if (seen[i])
            return c;
        seen[i] = 1;
    }
    return 'a';
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: First Letter to Appear Twice\n";
    std::cout << std::string(60, '=') << "\n";

    std::string s1 = "abccbaacz";
    std::cout << "\"" << s1 << "\" -> '" << repeatedCharacter(s1) << "'\n";

    std::string s2 = "abcdd";
    std::cout << "\"" << s2 << "\" -> '" << repeatedCharacter(s2) << "'\n";
}
