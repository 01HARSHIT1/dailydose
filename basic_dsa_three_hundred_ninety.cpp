/**
 * Basic DSA - Maximize Distance to Closest Person (LeetCode 849)
 * In a row of seats (0 empty, 1 occupied), pick an empty seat maximizing distance to nearest occupied.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maxDistToClosest(std::vector<int>& seats) {
    int n = static_cast<int>(seats.size());
    int prev = -1;
    int best = 0;
    for (int i = 0; i < n; ++i) {
        if (seats[i] == 1) {
            if (prev < 0)
                best = i;
            else
                best = std::max(best, (i - prev) / 2);
            prev = i;
        }
    }
    return std::max(best, n - 1 - prev);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Distance to Closest Person\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 0, 0, 0, 1, 0, 1};
    std::cout << "[1,0,0,0,1,0,1] -> " << maxDistToClosest(v1) << "\n";

    std::vector<int> v2 = {1, 0, 0, 0};
    std::cout << "[1,0,0,0] -> " << maxDistToClosest(v2) << "\n";
}
