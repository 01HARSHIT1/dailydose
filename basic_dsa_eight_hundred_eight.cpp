/**
 * Basic DSA - Minimum Operations to Make Elements Within K Subarrays Equal
 * (LeetCode 3505)
 * Sliding-window median cost plus DP to pick k non-overlapping windows.
 */

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

static constexpr long long kInfinity = LLONG_MAX / 2;

std::vector<long long> windowMedianCosts(const std::vector<int>& values,
                                         int windowSize) {
    std::vector<long long> costs;
    std::multiset<int> lowerHalf;
    std::multiset<int> upperHalf;
    long long lowerSum = 0;
    long long upperSum = 0;

    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        const int currentValue = values[index];

        if (lowerHalf.empty() || currentValue <= *lowerHalf.rbegin()) {
            lowerHalf.insert(currentValue);
            lowerSum += currentValue;
        } else {
            upperHalf.insert(currentValue);
            upperSum += currentValue;
        }

        if (index >= windowSize) {
            const int removedValue = values[index - windowSize];
            const auto iterator = lowerHalf.find(removedValue);
            if (iterator != lowerHalf.end()) {
                lowerHalf.erase(iterator);
                lowerSum -= removedValue;
            } else {
                upperHalf.erase(upperHalf.find(removedValue));
                upperSum -= removedValue;
            }
        }

        if (lowerHalf.size() < upperHalf.size()) {
            const int movedValue = *upperHalf.begin();
            upperHalf.erase(upperHalf.begin());
            lowerHalf.insert(movedValue);
            upperSum -= movedValue;
            lowerSum += movedValue;
        } else if (lowerHalf.size() > upperHalf.size() + 1) {
            const int movedValue = *lowerHalf.rbegin();
            lowerHalf.erase(std::prev(lowerHalf.end()));
            upperHalf.insert(movedValue);
            lowerSum -= movedValue;
            upperSum += movedValue;
        }

        if (index >= windowSize - 1) {
            const int median = *lowerHalf.rbegin();
            costs.push_back((median * static_cast<long long>(lowerHalf.size()) -
                             lowerSum) +
                            (upperSum - median * static_cast<long long>(upperHalf.size())));
        }
    }

    return costs;
}

long long minEqualSubarrayOperations(const std::vector<int>& values,
                                     int windowSize, int requiredCount) {
    const std::vector<long long> costs = windowMedianCosts(values, windowSize);
    std::vector<std::vector<long long>> memo(
        values.size() + 1, std::vector<long long>(requiredCount + 1, -1));

    std::function<long long(int, int)> depthFirstSearch =
        [&](int startIndex, int remainingWindows) -> long long {
        if (remainingWindows == 0)
            return 0;
        if (startIndex == static_cast<int>(values.size()))
            return kInfinity;
        if (memo[startIndex][remainingWindows] != -1)
            return memo[startIndex][remainingWindows];

        const long long skipWindow =
            depthFirstSearch(startIndex + 1, remainingWindows);
        long long takeWindow = kInfinity;

        if (startIndex + windowSize <= static_cast<int>(values.size())) {
            takeWindow = costs[startIndex] +
                         depthFirstSearch(startIndex + windowSize,
                                          remainingWindows - 1);
        }

        return memo[startIndex][remainingWindows] =
                   std::min(skipWindow, takeWindow);
    };

    return depthFirstSearch(0, requiredCount);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Make Elements Within K "
                 "Subarrays Equal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minEqualSubarrayOperations({5, -2, 1, 3, 7, 3, 6, 4, -1}, 3, 2)
              << "\n";

    std::cout << "sample 2 -> "
              << minEqualSubarrayOperations({9, -2, -2, -2, 1, 5}, 2, 2) << "\n";
}
