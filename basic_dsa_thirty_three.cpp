/**
 * Basic DSA - Ransom Note (LeetCode 383)
 * Check if ransomNote can be constructed from magazine.
 */
#include <iostream>
#include <string>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::vector<int> count(26, 0);
    for (char c : magazine) count[c - 'a']++;
    for (char c : ransomNote) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Ransom Note\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "a, b -> " << (canConstruct("a", "b") ? "true" : "false") << "\n";
    std::cout << "aa, ab -> " << (canConstruct("aa", "ab") ? "true" : "false") << "\n";
    std::cout << "aa, aab -> " << (canConstruct("aa", "aab") ? "true" : "false") << "\n";
}
