/**
 * Basic DSA - Magnetic Force Between Two Balls (LeetCode 1552)
 * m balls in n baskets at sorted positions; maximize minimum pairwise gap. Binary search gap; greedy placement from the left.
 */
#include <algorithm>
#include <iostream>
#include <vector>

bool canPlace(const std::vector<int>& pos, int m, int minDist) {
    int placed = 1;
    int last = pos[0];
    for (size_t i = 1; i < pos.size(); ++i) {
        if (pos[i] - last >= minDist) {
            ++placed;
            last = pos[i];
            if (placed >= m)
                return true;
        }
    }
    return placed >= m;
}

int maxDistance(std::vector<int> position, int m) {
    std::sort(position.begin(), position.end());
    int lo = 1;
    int hi = position.back() - position.front();
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (canPlace(position, m, mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Magnetic Force Between Two Balls\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[1,2,3,4,7] m=3 -> " << maxDistance({1, 2, 3, 4, 7}, 3) << "\n";
    std::cout << "[5,4,3,2,1,1000000000] m=2 -> " << maxDistance({5, 4, 3, 2, 1, 1000000000}, 2) << "\n";
}
