/**
 * Basic DSA - Permutation in String (LeetCode 567)
 * Check if s2 contains a permutation of s1 (sliding window + frequency).
 */
#include <iostream>
#include <string>
#include <vector>

bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size()) return false;
    std::vector<int> need(26, 0), cur(26, 0);
    for (char c : s1) need[c - 'a']++;
    for (int i = 0; i < (int)s1.size(); i++) cur[s2[i] - 'a']++;
    if (need == cur) return true;
    for (int i = (int)s1.size(); i < (int)s2.size(); i++) {
        cur[s2[i] - 'a']++;
        cur[s2[i - s1.size()] - 'a']--;
        if (need == cur) return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Permutation in String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "ab, eidbaooo -> " << (checkInclusion("ab", "eidbaooo") ? "true" : "false") << "\n";
    std::cout << "ab, eidboaoo -> " << (checkInclusion("ab", "eidboaoo") ? "true" : "false") << "\n";
    std::cout << "adc, dcda -> " << (checkInclusion("adc", "dcda") ? "true" : "false") << "\n";
}
