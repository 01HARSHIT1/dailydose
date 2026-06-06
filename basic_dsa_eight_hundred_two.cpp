/**
 * Basic DSA - Merge Operations for Minimum Travel Time (LeetCode 3538)
 * DP over segment merges to minimize distance-weighted travel time.
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

long long minTravelTime(int roadLength, int signCount, int mergeCount,
                        const std::vector<int>& positions,
                        const std::vector<int>& segmentTimes) {
    (void)roadLength;

    std::vector<long long> prefixTimes(signCount);
    prefixTimes[0] = segmentTimes[0];
    for (int index = 1; index < signCount; ++index) {
        prefixTimes[index] = prefixTimes[index - 1] + segmentTimes[index];
    }

    const long long infinity = 1e18;
    std::vector<std::vector<std::vector<long long>>> memo(
        signCount, std::vector<std::vector<long long>>(
                       mergeCount + 1,
                       std::vector<long long>(signCount, -1)));

    std::function<long long(int, int, int)> depthFirstSearch =
        [&](int currentIndex, int remainingSkips, int segmentStart) -> long long {
        if (currentIndex == signCount - 1) {
            return remainingSkips == 0 ? 0LL : infinity;
        }

        if (memo[currentIndex][remainingSkips][segmentStart] != -1) {
            return memo[currentIndex][remainingSkips][segmentStart];
        }

        const long long segmentRate =
            prefixTimes[currentIndex] -
            (segmentStart > 0 ? prefixTimes[segmentStart - 1] : 0LL);
        long long bestTime = infinity;
        const int farthestIndex =
            std::min(signCount - 1, currentIndex + remainingSkips + 1);

        for (int nextIndex = currentIndex + 1; nextIndex <= farthestIndex;
             ++nextIndex) {
            const long long distance =
                positions[nextIndex] - positions[currentIndex];
            bestTime = std::min(
                bestTime,
                distance * segmentRate +
                    depthFirstSearch(nextIndex,
                                     remainingSkips - (nextIndex - currentIndex - 1),
                                     currentIndex + 1));
        }

        memo[currentIndex][remainingSkips][segmentStart] = bestTime;
        return bestTime;
    };

    return depthFirstSearch(0, mergeCount, 0);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Operations for Minimum Travel Time\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minTravelTime(1, 4, 1, {0, 3, 8, 10}, {5, 8, 3, 6}) << "\n";

    std::cout << "sample 2 -> "
              << minTravelTime(5, 5, 1, {0, 1, 2, 3, 5}, {8, 3, 9, 3, 3})
              << "\n";
}
