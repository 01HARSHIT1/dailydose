/**
 * Basic DSA - Heaters (LeetCode 475)
 * Minimize heater radius so every house lies within some heater's warmth. Sort; each house takes nearest heater distance; answer is the max of those.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int findRadius(std::vector<int> houses, std::vector<int> heaters) {
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int h : houses) {
        auto it = std::lower_bound(heaters.begin(), heaters.end(), h);
        int need = INT_MAX;
        if (it != heaters.end())
            need = std::min(need, *it - h);
        if (it != heaters.begin())
            need = std::min(need, h - *std::prev(it));
        ans = std::max(ans, need);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Heaters\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "houses [1,2,3], heaters [2]       -> " << findRadius({1, 2, 3}, {2}) << "\n";
    std::cout << "houses [1,2,3,4], heaters [1,4]   -> " << findRadius({1, 2, 3, 4}, {1, 4}) << "\n";
}
