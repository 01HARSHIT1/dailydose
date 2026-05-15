/**
 * Basic DSA - Russian Doll Envelopes (LeetCode 354)
 * Max nested dolls: sort by width ascending, height descending for ties, then LIS on heights.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maxEnvelopes(std::vector<std::vector<int>> envelopes) {
    std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    std::vector<int> tails;
    for (const auto& e : envelopes) {
        int h = e[1];
        auto it = std::lower_bound(tails.begin(), tails.end(), h);
        if (it == tails.end())
            tails.push_back(h);
        else
            *it = h;
    }
    return static_cast<int>(tails.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Russian Doll Envelopes\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[[5,4],[6,4],[6,7],[2,3]]     -> " << maxEnvelopes({{5, 4}, {6, 4}, {6, 7}, {2, 3}})
              << "\n";
    std::cout << "[[1,1],[1,1],[1,1]]           -> " << maxEnvelopes({{1, 1}, {1, 1}, {1, 1}}) << "\n";
    std::cout << "[[4,5],[4,6],[6,7],[2,3],[1,1]] -> " << maxEnvelopes({{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}})
              << "\n";
}
