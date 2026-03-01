/**
 * Basic DSA - Insert Interval (LeetCode 57)
 * Insert new interval and merge overlaps.
 */
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    std::vector<std::vector<int>> out;
    int i = 0, n = (int)intervals.size();
    while (i < n && intervals[i][1] < newInterval[0])
        out.push_back(intervals[i++]);
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        i++;
    }
    out.push_back(newInterval);
    while (i < n) out.push_back(intervals[i++]);
    return out;
}

void print(std::vector<std::vector<int>>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Insert Interval\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1,3},{6,9}};
    std::vector<int> ni1 = {2,5};
    auto r1 = insert(a1, ni1);
    std::cout << "[[1,3],[6,9]], [2,5] -> ";
    print(r1);

    std::vector<std::vector<int>> a2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> ni2 = {4,8};
    auto r2 = insert(a2, ni2);
    std::cout << "[[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8] -> ";
    print(r2);
}
