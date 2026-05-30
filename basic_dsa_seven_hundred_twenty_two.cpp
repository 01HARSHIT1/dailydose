/**
 * Basic DSA - Maximum Students on a Single Bench (LeetCode 3450)
 * Group students by bench; return the largest count of unique student IDs.
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int maxStudentsOnBench(const std::vector<std::vector<int>>& students) {
    std::unordered_map<int, std::unordered_set<int>> benchToStudents;
    for (const auto& entry : students)
        benchToStudents[entry[1]].insert(entry[0]);

    int ans = 0;
    for (const auto& pair : benchToStudents)
        ans = std::max(ans, static_cast<int>(pair.second.size()));
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Students on a Single Bench\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxStudentsOnBench({{1, 2}, {2, 2}, {3, 3}, {1, 3}, {2, 3}}) << "\n";
    std::cout << "sample 2 -> "
              << maxStudentsOnBench({{1, 1}, {1, 1}}) << "\n";
}
