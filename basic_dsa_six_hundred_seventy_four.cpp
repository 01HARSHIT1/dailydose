/**
 * Basic DSA - Count Prefix and Suffix Pairs I (LeetCode 3042)
 * Count pairs (i,j), i<j, where words[i] is both a prefix and a suffix of words[j].
 */
#include <iostream>
#include <string>
#include <vector>

bool isPrefixAndSuffix(const std::string& a, const std::string& b) {
    if (a.size() > b.size())
        return false;
    bool prefix = b.compare(0, a.size(), a) == 0;
    bool suffix = b.compare(b.size() - a.size(), a.size(), a) == 0;
    return prefix && suffix;
}

int countPrefixSuffixPairs(const std::vector<std::string>& words) {
    int count = 0;
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (isPrefixAndSuffix(words[i], words[j]))
                ++count;
        }
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Prefix and Suffix Pairs I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countPrefixSuffixPairs({"a", "aba", "ababa", "aa"}) << "\n";
    std::cout << "sample 2 -> " << countPrefixSuffixPairs({"pa", "papa", "ma", "mama"}) << "\n";
    std::cout << "sample 3 -> " << countPrefixSuffixPairs({"abab", "ab"}) << "\n";
}
