/**
 * Basic DSA - Find Valid Pair of Adjacent Digits in String (LeetCode 3438)
 * Count digit frequencies, then return the first adjacent pair where each
 * digit appears in s exactly as many times as its numeric value.
 */
#include <iostream>
#include <string>
#include <vector>

std::string findValidPair(const std::string& s) {
    std::vector<int> count(10, 0);
    for (char c : s)
        ++count[c - '0'];

    for (size_t i = 1; i < s.size(); ++i) {
        int a = s[i - 1] - '0';
        int b = s[i] - '0';
        if (a != b && count[a] == a && count[b] == b)
            return s.substr(i - 1, 2);
    }
    return "";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Valid Pair of Adjacent Digits in String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> \"" << findValidPair("2523533") << "\"\n";
    std::cout << "sample 2 -> \"" << findValidPair("221") << "\"\n";
    std::cout << "sample 3 -> \"" << findValidPair("22") << "\"\n";
}
