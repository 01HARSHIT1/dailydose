/**
 * Basic DSA - Maximum Subsequence Score (LeetCode 2542)
 * Pick k indices; score = (sum of nums1[i]) * min(nums2[i]). Sort by nums2 descending; min-heap keeps k largest nums1 seen so far.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

long long maxScore(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    int n = static_cast<int>(nums1.size());
    std::vector<int> order(static_cast<size_t>(n));
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(),
              [&](int i, int j) { return nums2[static_cast<size_t>(i)] > nums2[static_cast<size_t>(j)]; });

    std::priority_queue<int, std::vector<int>, std::greater<int>> smallest;
    long long sum = 0;
    long long best = 0;
    for (int i = 0; i < n; ++i) {
        int idx = order[static_cast<size_t>(i)];
        sum += nums1[static_cast<size_t>(idx)];
        smallest.push(nums1[static_cast<size_t>(idx)]);
        if (static_cast<int>(smallest.size()) > k) {
            sum -= smallest.top();
            smallest.pop();
        }
        if (static_cast<int>(smallest.size()) == k)
            best = std::max(best, sum * static_cast<long long>(nums2[static_cast<size_t>(idx)]));
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Subsequence Score\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxScore({1, 3, 3, 2}, {2, 1, 3, 4}, 3) << "\n";
    std::cout << "sample 2 -> " << maxScore({4, 2, 3, 1, 1}, {7, 5, 10, 9, 6}, 1) << "\n";
}
