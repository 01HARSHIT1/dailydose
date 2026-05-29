/**
 * Basic DSA - Maximum Manhattan Distance After K Changes (LeetCode 3443)
 * Try four quadrant pairs (NE, NW, SE, SW); greedily flip up to k moves.
 */
#include <algorithm>
#include <iostream>
#include <string>

int calcDistance(const std::string& s, int k, char a, char b) {
    int ans = 0;
    int mx = 0;
    int changes = 0;

    for (char c : s) {
        if (c == a || c == b)
            ++mx;
        else if (changes < k) {
            ++changes;
            ++mx;
        } else
            --mx;
        ans = std::max(ans, mx);
    }
    return ans;
}

int maxDistance(const std::string& s, int k) {
    return std::max({calcDistance(s, k, 'N', 'E'), calcDistance(s, k, 'N', 'W'),
                     calcDistance(s, k, 'S', 'E'), calcDistance(s, k, 'S', 'W')});
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Manhattan Distance After K Changes\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxDistance("NWSE", 1) << "\n";
    std::cout << "sample 2 -> " << maxDistance("NSWWEW", 3) << "\n";
}
