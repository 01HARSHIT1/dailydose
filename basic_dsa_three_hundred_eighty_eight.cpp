/**
 * Basic DSA - Positions of Large Groups (LeetCode 830)
 * Intervals [l,r] (inclusive) where the same letter runs for length >= 3.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> largeGroupPositions(const std::string& s) {
    std::vector<std::vector<int>> ans;
    int n = static_cast<int>(s.size());
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i])
            ++j;
        if (j - i >= 3)
            ans.push_back({i, j - 1});
        i = j;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Positions of Large Groups\n";
    std::cout << std::string(60, '=') << "\n";

    auto a1 = largeGroupPositions("abbxxxxzzy");
    std::cout << "abbxxxxzzy -> ";
    for (size_t i = 0; i < a1.size(); ++i)
        std::cout << (i ? ", " : "") << "[" << a1[i][0] << "," << a1[i][1] << "]";
    std::cout << "\n";

    auto a2 = largeGroupPositions("abc");
    std::cout << "abc -> ";
    for (size_t i = 0; i < a2.size(); ++i)
        std::cout << (i ? ", " : "") << "[" << a2[i][0] << "," << a2[i][1] << "]";
    if (a2.empty())
        std::cout << "(none)";
    std::cout << "\n";
}
