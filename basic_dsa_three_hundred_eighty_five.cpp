/**
 * Basic DSA - Shortest Distance to a Character (LeetCode 821)
 * For each index in s, distance to the closest occurrence of c.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> shortestToChar(const std::string& s, char c) {
    int n = static_cast<int>(s.size());
    std::vector<int> ans(n);
    for (int i = 0, prev = -n; i < n; ++i) {
        if (s[i] == c)
            prev = i;
        ans[i] = i - prev;
    }
    for (int i = n - 1, prev = 2 * n; i >= 0; --i) {
        if (s[i] == c)
            prev = i;
        ans[i] = std::min(ans[i], prev - i);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Shortest Distance to a Character\n";
    std::cout << std::string(60, '=') << "\n";

    auto a1 = shortestToChar("loveleetcode", 'e');
    std::cout << "loveleetcode, e -> ";
    for (size_t i = 0; i < a1.size(); ++i)
        std::cout << (i ? "," : "") << a1[i];
    std::cout << "\n";

    auto a2 = shortestToChar("aaba", 'b');
    std::cout << "aaba, b -> ";
    for (size_t i = 0; i < a2.size(); ++i)
        std::cout << (i ? "," : "") << a2[i];
    std::cout << "\n";
}
