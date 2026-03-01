/**
 * Basic DSA - Non-overlapping Intervals (LeetCode 435)
 * Remove minimum intervals to make the rest non-overlapping.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    int count = 0, end = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < end) count++;
        else end = intervals[i][1];
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Non-overlapping Intervals\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1,2},{2,3},{3,4},{1,3}};
    std::cout << "[[1,2],[2,3],[3,4],[1,3]] -> " << eraseOverlapIntervals(a1) << "\n";

    std::vector<std::vector<int>> a2 = {{1,2},{1,2},{1,2}};
    std::cout << "[[1,2],[1,2],[1,2]] -> " << eraseOverlapIntervals(a2) << "\n";

    std::vector<std::vector<int>> a3 = {{1,2},{2,3}};
    std::cout << "[[1,2],[2,3]] -> " << eraseOverlapIntervals(a3) << "\n";
}
