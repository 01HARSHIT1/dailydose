/**
 * Basic DSA - Merge Intervals (LeetCode 56)
 * Merge overlapping intervals.
 */
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return {};
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> out = {intervals[0]};
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= out.back()[1])
            out.back()[1] = std::max(out.back()[1], intervals[i][1]);
        else
            out.push_back(intervals[i]);
    }
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
    std::cout << "Problem: Merge Intervals\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = merge(a1);
    std::cout << "[[1,3],[2,6],[8,10],[15,18]] -> ";
    print(r1);

    std::vector<std::vector<int>> a2 = {{1,4},{4,5}};
    auto r2 = merge(a2);
    std::cout << "[[1,4],[4,5]] -> ";
    print(r2);
}
