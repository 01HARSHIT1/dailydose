/**
 * Basic DSA - Longest Common Prefix (LeetCode 14)
 * Find longest common prefix string amongst array of strings.
 */
#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    for (size_t i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];
        for (size_t j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Common Prefix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> a1 = {"flower", "flow", "flight"};
    std::cout << "[flower,flow,flight] -> \"" << longestCommonPrefix(a1) << "\"\n";

    std::vector<std::string> a2 = {"dog", "racecar", "car"};
    std::cout << "[dog,racecar,car] -> \"" << longestCommonPrefix(a2) << "\"\n";

    std::vector<std::string> a3 = {"a"};
    std::cout << "[a] -> \"" << longestCommonPrefix(a3) << "\"\n";
}
