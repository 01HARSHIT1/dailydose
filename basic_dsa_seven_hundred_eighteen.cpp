/**
 * Basic DSA - Reschedule Meetings for Maximum Free Time II (LeetCode 3440)
 * Reschedule at most one meeting; merge its slot if it fits in another gap.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> buildGaps(int eventTime, const std::vector<int>& startTime,
                           const std::vector<int>& endTime) {
    int n = static_cast<int>(endTime.size());
    std::vector<int> gaps(n + 1);
    gaps[0] = startTime[0];
    for (int i = 1; i < n; ++i)
        gaps[i] = startTime[i] - endTime[i - 1];
    gaps[n] = eventTime - endTime[n - 1];
    return gaps;
}

int maxFreeTimeII(int eventTime, const std::vector<int>& startTime,
                  const std::vector<int>& endTime) {
    int n = static_cast<int>(endTime.size());
    std::vector<int> gaps = buildGaps(eventTime, startTime, endTime);

    std::vector<int> maxLeft(n + 1, 0);
    std::vector<int> maxRight(n + 1, 0);
    maxLeft[0] = gaps[0];
    maxRight[n] = gaps[n];
    for (int i = 1; i <= n; ++i)
        maxLeft[i] = std::max(gaps[i], maxLeft[i - 1]);
    for (int i = n - 1; i >= 0; --i)
        maxRight[i] = std::max(gaps[i], maxRight[i + 1]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int meetingLen = endTime[i] - startTime[i];
        int adjacentGap = gaps[i] + gaps[i + 1];
        int leftGap = (i > 0) ? maxLeft[i - 1] : 0;
        int rightGap = (i + 2 <= n) ? maxRight[i + 2] : 0;
        bool canMove = meetingLen <= std::max(leftGap, rightGap);
        ans = std::max(ans, adjacentGap + (canMove ? meetingLen : 0));
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reschedule Meetings for Maximum Free Time II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxFreeTimeII(5, {1, 3}, {2, 5}) << "\n";
    std::cout << "sample 2 -> "
              << maxFreeTimeII(10, {0, 7, 9}, {1, 8, 10}) << "\n";
    std::cout << "sample 3 -> "
              << maxFreeTimeII(10, {0, 3, 7, 9}, {1, 4, 8, 10}) << "\n";
}
