/**
 * Basic DSA - Meeting Rooms (LeetCode 252)
 * Check if one person can attend all meetings (no overlaps).
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Meeting Rooms\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{0,30},{5,10},{15,20}};
    std::cout << "[[0,30],[5,10],[15,20]] -> " << (canAttendMeetings(a1) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> a2 = {{7,10},{2,4}};
    std::cout << "[[7,10],[2,4]] -> " << (canAttendMeetings(a2) ? "true" : "false") << "\n";
}
