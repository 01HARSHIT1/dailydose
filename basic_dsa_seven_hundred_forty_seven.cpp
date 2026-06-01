/**
 * Basic DSA - Permutation Difference between Two Strings (LeetCode 3470)
 * Sum absolute index differences for each character across two permutations.
 */

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

int findPermutationDifference(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> indexInS;
    std::unordered_map<char, int> indexInT;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        indexInS[s[i]] = i;
        indexInT[t[i]] = i;
    }

    int difference = 0;
    for (const auto& entry : indexInS)
        difference += std::abs(entry.second - indexInT[entry.first]);

    return difference;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Permutation Difference between Two Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << findPermutationDifference("abc", "bac") << "\n";
    std::cout << "sample 2 -> " << findPermutationDifference("abcde", "edbac") << "\n";
}
