/**
 * Basic DSA - Meeting Rooms III (LeetCode 2402)
 * n rooms; assign each meeting to the free room with smallest index, or the one that frees earliest. Return the room that hosts the most meetings.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int mostBooked(int n, std::vector<std::vector<int>> meetings) {
    std::sort(meetings.begin(), meetings.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> freeRooms;
    for (int r = 0; r < n; ++r)
        freeRooms.push(r);

    struct BusyCmp {
        bool operator()(const std::pair<long long, int>& a, const std::pair<long long, int>& b) const {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        }
    };
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, BusyCmp> busy;

    std::vector<int> used(static_cast<size_t>(n), 0);
    for (const auto& meet : meetings) {
        long long start = meet[0];
        long long end = meet[1];
        long long dur = end - start;

        while (!busy.empty() && busy.top().first <= start) {
            freeRooms.push(busy.top().second);
            busy.pop();
        }
        if (freeRooms.empty()) {
            auto top = busy.top();
            busy.pop();
            start = std::max(start, top.first);
            end = start + dur;
            freeRooms.push(top.second);
        }
        int room = freeRooms.top();
        freeRooms.pop();
        ++used[static_cast<size_t>(room)];
        busy.push({end, room});
    }

    int best = 0;
    for (int r = 1; r < n; ++r) {
        if (used[static_cast<size_t>(r)] > used[static_cast<size_t>(best)])
            best = r;
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Meeting Rooms III\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=2 sample -> room " << mostBooked(2, {{0, 10}, {1, 5}, {2, 7}, {3, 4}}) << "\n";
    std::cout << "n=3 sample -> room " << mostBooked(3, {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}) << "\n";
}
