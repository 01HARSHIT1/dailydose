/**
 * Basic DSA - Find the Longest Semi-Repetitive Substring (LeetCode 2730)
 * Sliding window allowing at most one adjacent equal pair; shrink from the left when a second pair appears.
 */
#include <algorithm>
#include <iostream>
#include <string>

int longestSemiRepetitiveSubstring(const std::string& s) {
    int n = static_cast<int>(s.size());
    int best = 1;
    int left = 0;
    int pairs = 0;
    for (int right = 1; right < n; ++right) {
        if (s[static_cast<size_t>(right)] == s[static_cast<size_t>(right - 1)])
            ++pairs;
        while (pairs > 1) {
            ++left;
            if (s[static_cast<size_t>(left)] == s[static_cast<size_t>(left - 1)])
                --pairs;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Longest Semi-Repetitive Substring\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << longestSemiRepetitiveSubstring("52233") << "\n";
    std::cout << "sample 2 -> " << longestSemiRepetitiveSubstring("5494") << "\n";
    std::cout << "sample 3 -> " << longestSemiRepetitiveSubstring("1111111") << "\n";
}
