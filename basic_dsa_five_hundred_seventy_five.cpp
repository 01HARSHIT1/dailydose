/**
 * Basic DSA - Meeting Rooms II (LeetCode 253)
 * Min conference rooms needed. Sort by start; min-heap stores ongoing meetings' end times — reuse a room if smallest end <= start.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int minMeetingRooms(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });
    std::priority_queue<int, std::vector<int>, std::greater<int>> ends;
    for (const auto& iv : intervals) {
        if (!ends.empty() && ends.top() <= iv[0])
            ends.pop();
        ends.push(iv[1]);
    }
    return static_cast<int>(ends.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Meeting Rooms II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minMeetingRooms({{0, 30}, {5, 10}, {15, 20}}) << "\n";
    std::cout << "sample 2 -> " << minMeetingRooms({{7, 10}, {2, 4}}) << "\n";
}
