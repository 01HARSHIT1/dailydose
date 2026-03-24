/**
 * Basic DSA - Maximum Length of Pair Chain (LeetCode 646)
 * Pairs [a,b]; chain if b < c for the next [c,d]. Maximize chain length.
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });
    int ans = 0;
    int cur_end = std::numeric_limits<int>::min();
    for (const auto& p : pairs) {
        if (p[0] > cur_end) {
            cur_end = p[1];
            ++ans;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Length of Pair Chain\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> p1 = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << "[[1,2],[2,3],[3,4]] -> " << findLongestChain(p1) << "\n";

    std::vector<std::vector<int>> p2 = {{1, 2}, {7, 8}, {4, 5}};
    std::cout << "[[1,2],[7,8],[4,5]] -> " << findLongestChain(p2) << "\n";
}
