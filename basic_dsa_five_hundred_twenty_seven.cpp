/**
 * Basic DSA - Longest Common Prefix (LeetCode 14)
 * Among all strings in strs, return the longest prefix shared by every string.
 * Compare character by character until any string ends or differs.
 * Time: O(S) where S is sum of lengths, Space: O(1) extra (answer string excluded).
 */
#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty())
        return "";
    for (size_t i = 0;; ++i) {
        for (const std::string& s : strs) {
            if (i >= s.size() || s[i] != strs[0][i])
                return strs[0].substr(0, i);
        }
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Common Prefix\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[\"flower\",\"flow\",\"flight\"] -> \""
              << longestCommonPrefix({"flower", "flow", "flight"}) << "\"\n";
    std::cout << "[\"dog\",\"racecar\",\"car\"] -> \""
              << longestCommonPrefix({"dog", "racecar", "car"}) << "\"\n";
    std::cout << "[\"interspecies\",\"interstellar\",\"interstate\"] -> \""
              << longestCommonPrefix({"interspecies", "interstellar", "interstate"}) << "\"\n";
}
