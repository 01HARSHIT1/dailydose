/**
 * Basic DSA - Koko Eating Bananas (LeetCode 875)
 * Min integer speed k bananas/hour to finish all piles within h hours. Binary search k; check feasibility with ceiling division per pile.
 */
#include <algorithm>
#include <iostream>
#include <vector>

bool canFinish(const std::vector<int>& piles, int h, int k) {
    int hours = 0;
    for (int p : piles) {
        hours += (p + k - 1) / k;
        if (hours > h)
            return false;
    }
    return true;
}

int minEatingSpeed(const std::vector<int>& piles, int h) {
    int lo = 1;
    int hi = *std::max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canFinish(piles, h, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Koko Eating Bananas\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[3,6,7,11] h=8  -> " << minEatingSpeed({3, 6, 7, 11}, 8) << "\n";
    std::cout << "[30,11,23,4,20] h=5 -> " << minEatingSpeed({30, 11, 23, 4, 20}, 5) << "\n";
    std::cout << "[30,11,23,4,20] h=6 -> " << minEatingSpeed({30, 11, 23, 4, 20}, 6) << "\n";
}
