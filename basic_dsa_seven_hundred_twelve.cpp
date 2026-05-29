/**
 * Basic DSA - Reschedule Meetings for Maximum Free Time I (LeetCode 3439)
 * Reschedule at most k meetings to maximize the longest continuous free block.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maxFreeTime(int eventTime, int k, const std::vector<int>& startTime,
                const std::vector<int>& endTime) {
    int n = static_cast<int>(endTime.size());
    std::vector<int> gaps(n + 1);
    gaps[0] = startTime[0];
    for (int i = 1; i < n; ++i)
        gaps[i] = startTime[i] - endTime[i - 1];
    gaps[n] = eventTime - endTime[n - 1];

    int ans = 0;
    int windowSum = 0;
    for (int i = 0; i <= n; ++i) {
        windowSum += gaps[i];
        if (i >= k) {
            ans = std::max(ans, windowSum);
            windowSum -= gaps[i - k];
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reschedule Meetings for Maximum Free Time I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxFreeTime(5, 1, {1, 3}, {2, 5}) << "\n";
    std::cout << "sample 2 -> "
              << maxFreeTime(10, 1, {0, 2, 9}, {1, 4, 10}) << "\n";
    std::cout << "sample 3 -> "
              << maxFreeTime(5, 2, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}) << "\n";
}
