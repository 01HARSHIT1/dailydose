/**
 * Basic DSA - Minimum Time to Visit All Houses (LeetCode 3540)
 * Prefix sums on a circular street; each step takes the shorter forward/backward route.
 */

#include <algorithm>
#include <iostream>
#include <vector>

long long minTotalTime(const std::vector<int>& forward,
                       const std::vector<int>& backward,
                       const std::vector<int>& queries) {
    const int houseCount = static_cast<int>(forward.size());
    long long backwardSum = 0;
    for (const int segment : backward)
        backwardSum += segment;

    std::vector<long long> prefixForward(houseCount + 1, 0);
    std::vector<long long> prefixBackward(houseCount, 0);

    for (int index = 0; index < houseCount; ++index) {
        prefixForward[index + 1] = prefixForward[index] + forward[index];
        prefixBackward[index] =
            (index == 0 ? 0LL : prefixBackward[index - 1]) + backward[index];
    }

    long long totalTime = 0;
    int currentHouse = 0;

    for (const int targetHouse : queries) {
        const long long forwardDistance =
            (targetHouse < currentHouse ? prefixForward[houseCount] : 0LL) +
            prefixForward[targetHouse] - prefixForward[currentHouse];
        const long long backwardDistance =
            (targetHouse > currentHouse ? backwardSum : 0LL) +
            prefixBackward[currentHouse] - prefixBackward[targetHouse];

        totalTime += std::min(forwardDistance, backwardDistance);
        currentHouse = targetHouse;
    }

    return totalTime;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Time to Visit All Houses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minTotalTime({1, 4, 4}, {4, 1, 2}, {1, 2, 0, 2}) << "\n";

    std::cout << "sample 2 -> "
              << minTotalTime({1, 1, 1, 1}, {2, 2, 2, 2}, {1, 2, 3, 0}) << "\n";
}
