/**
 * Basic DSA - Move Pieces to Obtain a String (LeetCode 2337)
 * Compare L/R order in start vs target; L can only move left, R only right, so positions must be reachable.
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>

bool canChange(const std::string& start, const std::string& target) {
    std::vector<std::pair<char, int>> from;
    std::vector<std::pair<char, int>> to;
    for (int i = 0; i < static_cast<int>(start.size()); ++i) {
        if (start[static_cast<size_t>(i)] != '_')
            from.push_back({start[static_cast<size_t>(i)], i});
    }
    for (int i = 0; i < static_cast<int>(target.size()); ++i) {
        if (target[static_cast<size_t>(i)] != '_')
            to.push_back({target[static_cast<size_t>(i)], i});
    }
    if (from.size() != to.size())
        return false;
    for (size_t i = 0; i < from.size(); ++i) {
        if (from[i].first != to[i].first)
            return false;
        if (from[i].first == 'L' && from[i].second < to[i].second)
            return false;
        if (from[i].first == 'R' && from[i].second > to[i].second)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Move Pieces to Obtain a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << canChange("_L__R__R_", "L______RR") << "\n";
    std::cout << "sample 2 -> " << canChange("R_L_", "__LR") << "\n";
    std::cout << "sample 3 -> " << canChange("_R", "R_") << "\n";
}
