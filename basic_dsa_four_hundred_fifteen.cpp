/**
 * Basic DSA - Number of Equivalent Domino Pairs (LeetCode 1128)
 * [a,b] = [b,a]; count unordered pairs of equivalent dominoes.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int numEquivDominoPairs(const std::vector<std::vector<int>>& dominoes) {
    std::vector<int> cnt(100);
    int ans = 0;
    for (const auto& d : dominoes) {
        int lo = std::min(d[0], d[1]);
        int hi = std::max(d[0], d[1]);
        int k = lo * 10 + hi;
        ans += cnt[k];
        ++cnt[k];
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Equivalent Domino Pairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> d1 = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    std::cout << "[[1,2],[2,1],[3,4],[5,6]] -> " << numEquivDominoPairs(d1) << "\n";

    std::vector<std::vector<int>> d2 = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
    std::cout << "five dominoes (example 2) -> " << numEquivDominoPairs(d2) << "\n";
}
