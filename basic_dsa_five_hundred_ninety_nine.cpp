/**
 * Basic DSA - Maximum Number of Events That Can Be Attended (LeetCode 1353)
 * One event per day; pick the one ending soonest among those already started. Sort by start; min-heap of end days.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int maxEvents(std::vector<std::vector<int>> events) {
    std::sort(events.begin(), events.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> ending;
    int attended = 0;
    int day = 0;
    int i = 0;
    int n = static_cast<int>(events.size());
    while (i < n || !ending.empty()) {
        if (ending.empty())
            day = events[static_cast<size_t>(i)][0];
        while (i < n && events[static_cast<size_t>(i)][0] <= day) {
            ending.push(events[static_cast<size_t>(i)][1]);
            ++i;
        }
        ending.pop();
        ++attended;
        ++day;
        while (!ending.empty() && ending.top() < day)
            ending.pop();
    }
    return attended;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Events That Can Be Attended\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[[1,2],[2,3],[3,4]]           -> " << maxEvents({{1, 2}, {2, 3}, {3, 4}}) << "\n";
    std::cout << "[[1,2],[1,2],[1,2]]           -> " << maxEvents({{1, 2}, {1, 2}, {1, 2}}) << "\n";
    std::cout << "[[1,4],[4,4],[2,2],[3,4],[1,1]] -> " << maxEvents({{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}})
              << "\n";
}
