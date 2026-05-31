/**
 * Basic DSA - Maximum Sum With at Most K Elements (LeetCode 3462)
 * Pick at most k matrix elements with per-row limits; maximize total sum.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

long long maxSum(std::vector<std::vector<int>> grid, std::vector<int> limits, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
        std::sort(grid[i].begin(), grid[i].end());
        const int take = std::min(limits[i], static_cast<int>(grid[i].size()));

        for (int j = 0; j < take; ++j) {
            minHeap.push(grid[i][static_cast<int>(grid[i].size()) - j - 1]);
            if (static_cast<int>(minHeap.size()) > k)
                minHeap.pop();
        }
    }

    long long ans = 0;
    while (!minHeap.empty()) {
        ans += minHeap.top();
        minHeap.pop();
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Sum With at Most K Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxSum({{1, 2}, {3, 4}}, {1, 2}, 2) << "\n";
    std::cout << "sample 2 -> " << maxSum({{5, 3, 7}, {8, 2, 6}}, {2, 2}, 3) << "\n";
}
