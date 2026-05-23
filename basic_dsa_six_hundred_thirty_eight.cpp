/**
 * Basic DSA - Find the Substring With Maximum Cost (LeetCode 2606)
 * Map each char to its value (custom or position), then run Kadane's algorithm allowing the empty substring.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maximumCostSubstring(const std::string& s, const std::string& chars, const std::vector<int>& vals) {
    std::vector<int> value(26);
    for (int i = 0; i < 26; ++i)
        value[static_cast<size_t>(i)] = i + 1;
    for (size_t i = 0; i < chars.size(); ++i)
        value[static_cast<size_t>(chars[i] - 'a')] = vals[i];

    int best = 0;
    int current = 0;
    for (char ch : s) {
        current = std::max(0, current + value[static_cast<size_t>(ch - 'a')]);
        best = std::max(best, current);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Substring With Maximum Cost\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumCostSubstring("adaa", "d", {-1000}) << "\n";
    std::cout << "sample 2 -> " << maximumCostSubstring("abc", "abc", {-1, -1, -1}) << "\n";
}
