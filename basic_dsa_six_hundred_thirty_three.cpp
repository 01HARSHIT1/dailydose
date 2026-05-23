/**
 * Basic DSA - Find Score of an Array After Marking All Elements (LeetCode 2593)
 * Repeatedly pick the smallest unmarked value (ties by index), add to score, mark it and its neighbors.
 */
#include <algorithm>
#include <iostream>
#include <vector>

long long findScore(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<std::pair<int, int>> order;
    order.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i)
        order.push_back({nums[static_cast<size_t>(i)], i});
    std::sort(order.begin(), order.end());

    std::vector<bool> marked(static_cast<size_t>(n), false);
    long long score = 0;
    for (const auto& item : order) {
        int idx = item.second;
        if (marked[static_cast<size_t>(idx)])
            continue;
        score += item.first;
        marked[static_cast<size_t>(idx)] = true;
        if (idx > 0)
            marked[static_cast<size_t>(idx - 1)] = true;
        if (idx + 1 < n)
            marked[static_cast<size_t>(idx + 1)] = true;
    }
    return score;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Score of an Array After Marking All Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << findScore({2, 1, 3, 4, 5, 2}) << "\n";
    std::cout << "sample 2 -> " << findScore({2, 3, 5, 1, 3, 2}) << "\n";
}
