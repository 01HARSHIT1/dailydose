/**
 * Basic DSA - IPO (LeetCode 502)
 * Pick up to k projects; need capital[i] to start project i, earn profits[i]. Greedy: take max profit among affordable (two heaps / sort + max-heap).
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
    int n = static_cast<int>(profits.size());
    std::vector<int> order(static_cast<size_t>(n));
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int i, int j) {
        return capital[static_cast<size_t>(i)] < capital[static_cast<size_t>(j)];
    });
    std::priority_queue<int> bestProfit;
    int idx = 0;
    for (int round = 0; round < k; ++round) {
        while (idx < n && capital[static_cast<size_t>(order[static_cast<size_t>(idx)])] <= w) {
            bestProfit.push(profits[static_cast<size_t>(order[static_cast<size_t>(idx)])]);
            ++idx;
        }
        if (bestProfit.empty())
            break;
        w += bestProfit.top();
        bestProfit.pop();
    }
    return w;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: IPO\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> p1 = {1, 2, 3};
    std::vector<int> c1 = {0, 1, 1};
    std::cout << "k=2 w=0 sample -> " << findMaximizedCapital(2, 0, p1, c1) << "\n";

    std::vector<int> p2 = {1, 2, 3};
    std::vector<int> c2 = {0, 1, 2};
    std::cout << "k=3 w=0          -> " << findMaximizedCapital(3, 0, p2, c2) << "\n";
}
