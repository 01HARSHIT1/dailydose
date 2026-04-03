/**
 * Basic DSA - Longest Common Prefix (LeetCode 14)
 * Among all strings, longest prefix shared by every string (or "" if none).
 */
#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty())
        return "";
    const std::string& first = strs[0];
    for (size_t i = 0; i < first.size(); ++i) {
        char c = first[i];
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != c)
                return first.substr(0, i);
        }
    }
    return first;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Common Prefix\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[flower,flow,flight] -> \"" << longestCommonPrefix({"flower", "flow", "flight"})
              << "\"\n";
    std::cout << "[dog,racecar,car] -> \"" << longestCommonPrefix({"dog", "racecar", "car"}) << "\"\n";
}
