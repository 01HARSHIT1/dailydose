/**
 * Basic DSA - Maximum Bags With Full Capacity of Balls (LeetCode 2279)
 * Each bag needs `capacity[i] - rocks[i]` more balls to be full. Sort remaining space ascending; greedily fill cheapest bags first with `additional` rocks.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maximumBags(const std::vector<int>& capacity, const std::vector<int>& rocks, int additional) {
    int n = static_cast<int>(capacity.size());
    std::vector<int> need(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i)
        need[static_cast<size_t>(i)] = capacity[static_cast<size_t>(i)] - rocks[static_cast<size_t>(i)];
    std::sort(need.begin(), need.end());
    int full = 0;
    for (int gap : need) {
        if (additional < gap)
            break;
        additional -= gap;
        ++full;
    }
    return full;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Bags With Full Capacity of Balls\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumBags({2, 3, 4, 5}, {1, 2, 4, 4}, 2) << "\n";
    std::cout << "sample 2 -> " << maximumBags({1, 2, 3}, {1, 2, 3}, 5) << "\n";
}
