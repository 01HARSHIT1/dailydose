/**
 * Basic DSA - Button with Longest Push Time (LeetCode 3386)
 * Press duration is the gap since the previous event; pick the longest (smallest index on ties).
 */
#include <iostream>
#include <vector>

int buttonWithLongestTime(const std::vector<std::vector<int>>& events) {
    int bestIndex = 0;
    int bestDuration = 0;
    int previousTime = 0;

    for (const std::vector<int>& event : events) {
        int index = event[0];
        int time = event[1];
        int duration = time - previousTime;
        if (duration > bestDuration || (duration == bestDuration && index < bestIndex)) {
            bestDuration = duration;
            bestIndex = index;
        }
        previousTime = time;
    }
    return bestIndex;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Button with Longest Push Time\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << buttonWithLongestTime({{1, 2}, {2, 5}, {3, 9}, {1, 15}}) << "\n";
    std::cout << "sample 2 -> "
              << buttonWithLongestTime({{10, 5}, {1, 7}}) << "\n";
}
