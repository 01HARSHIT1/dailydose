/**
 * Basic DSA - Capacity To Ship Packages Within D Days (LeetCode 1011)
 * Min ship capacity so all weights ship in order within d days. Binary search capacity; greedy days for a fixed cap.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool canShipWithin(const std::vector<int>& weights, int days, int capacity) {
    int need = 1;
    int load = 0;
    for (int w : weights) {
        if (w > capacity)
            return false;
        if (load + w > capacity) {
            ++need;
            load = w;
        } else
            load += w;
        if (need > days)
            return false;
    }
    return true;
}

int shipWithinDays(const std::vector<int>& weights, int days) {
    int lo = *std::max_element(weights.begin(), weights.end());
    int hi = std::accumulate(weights.begin(), weights.end(), 0);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShipWithin(weights, days, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Capacity To Ship Packages Within D Days\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> w = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "1..10, d=5 -> " << shipWithinDays(w, 5) << "\n";
    std::vector<int> w2 = {3, 2, 2, 4, 1, 4};
    std::cout << "[3,2,2,4,1,4] d=3 -> " << shipWithinDays(w2, 3) << "\n";
}
