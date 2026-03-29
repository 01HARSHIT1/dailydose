/**
 * Basic DSA - Shuffle String (LeetCode 1528)
 * indices[i] is the final position of s[i] in the restored string.
 */
#include <iostream>
#include <string>
#include <vector>

std::string restoreString(const std::string& s, const std::vector<int>& indices) {
    std::string t(s.size(), ' ');
    for (size_t i = 0; i < s.size(); ++i)
        t[static_cast<size_t>(indices[i])] = s[i];
    return t;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Shuffle String\n";
    std::cout << std::string(60, '=') << "\n";

    std::string s1 = "codeleet";
    std::vector<int> idx1 = {4, 5, 6, 7, 0, 2, 1, 3};
    std::cout << restoreString(s1, idx1) << "\n";

    std::string s2 = "abc";
    std::vector<int> idx2 = {0, 1, 2};
    std::cout << restoreString(s2, idx2) << "\n";
}
