/**
 * Basic DSA - Merge Strings Alternately (LeetCode 1768)
 * Interleave characters from word1 and word2; append the rest of the longer word.
 */
#include <iostream>
#include <string>

std::string mergeAlternately(const std::string& word1, const std::string& word2) {
    std::string ans;
    size_t n = word1.size();
    size_t m = word2.size();
    size_t i = 0;
    while (i < n || i < m) {
        if (i < n)
            ans += word1[i];
        if (i < m)
            ans += word2[i];
        ++i;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Strings Alternately\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abc, pqr -> " << mergeAlternately("abc", "pqr") << "\n";
    std::cout << "ab, pqrs -> " << mergeAlternately("ab", "pqrs") << "\n";
}
