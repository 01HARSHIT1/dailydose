/**
 * Basic DSA - Minimum Cost to Make All Characters Equal (LeetCode 2712)
 * At each transition where s[i] != s[i-1], pay min(i, n - i) to flip a side.
 */
#include <algorithm>
#include <iostream>
#include <string>

long long minimumCost(const std::string& s) {
    int n = static_cast<int>(s.size());
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1])
            ans += std::min(i, n - i);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Cost to Make All Characters Equal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumCost("0011") << "\n";
    std::cout << "sample 2 -> " << minimumCost("010101") << "\n";
}
