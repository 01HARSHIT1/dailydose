/**
 * Basic DSA - Minimum Interval to Include Each Query (LeetCode 1851)
 * For each query point, smallest interval length (right-left+1) that covers it. Sort by start; min-heap of (size, right).
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> minInterval(std::vector<std::vector<int>> intervals, std::vector<int> queries) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<int, int>> order;
    order.reserve(queries.size());
    for (size_t i = 0; i < queries.size(); ++i)
        order.push_back({queries[i], static_cast<int>(i)});
    std::sort(order.begin(), order.end());

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        active; // size, right
    std::vector<int> ans(queries.size(), -1);
    int j = 0;
    int m = static_cast<int>(intervals.size());
    for (const auto& qidx : order) {
        int q = qidx.first;
        int idx = qidx.second;
        while (j < m && intervals[static_cast<size_t>(j)][0] <= q) {
            int sz = intervals[static_cast<size_t>(j)][1] - intervals[static_cast<size_t>(j)][0] + 1;
            active.push({sz, intervals[static_cast<size_t>(j)][1]});
            ++j;
        }
        while (!active.empty() && active.top().second < q)
            active.pop();
        if (!active.empty())
            ans[static_cast<size_t>(idx)] = active.top().first;
    }
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Interval to Include Each Query\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(minInterval({{1, 4}, {2, 4}, {3, 6}, {4, 4}}, {2, 3, 4, 5}));
    printVec(minInterval({{2, 3}, {2, 5}, {1, 8}, {20, 25}}, {2, 19, 5, 22}));
}
