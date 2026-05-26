/**
 * Basic DSA - Apple Redistribution into Boxes (LeetCode 3074)
 * Total apples must fit; use the largest boxes first, counting how many are needed.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int minimumBoxes(const std::vector<int>& apple, std::vector<int> capacity) {
    int total = std::accumulate(apple.begin(), apple.end(), 0);
    std::sort(capacity.rbegin(), capacity.rend());

    int used = 0;
    int filled = 0;
    for (int cap : capacity) {
        if (filled >= total)
            break;
        filled += cap;
        ++used;
    }
    return used;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Apple Redistribution into Boxes\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumBoxes({1, 3, 2}, {4, 3, 1, 5, 2}) << "\n";
    std::cout << "sample 2 -> " << minimumBoxes({5, 5, 5}, {2, 4, 2, 7}) << "\n";
}
