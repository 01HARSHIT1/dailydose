/**
 * Basic DSA - Calculate Score After Performing Instructions (LeetCode 3522)
 * Simulate add/jump instructions with visited-index tracking.
 */

#include <iostream>
#include <string>
#include <vector>

long long calculateScore(const std::vector<std::string>& instructions,
                         const std::vector<int>& values) {
    const int count = static_cast<int>(instructions.size());
    long long score = 0;
    int index = 0;
    std::vector<bool> visited(count, false);

    while (index >= 0 && index < count && !visited[index]) {
        visited[index] = true;
        if (instructions[index][0] == 'a') {
            score += values[index];
            ++index;
        } else {
            index += values[index];
        }
    }

    return score;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Calculate Score After Performing Instructions\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << calculateScore({"jump", "add", "add", "jump", "add", "jump"},
                                {2, 1, 3, 1, -2, -3})
              << "\n";

    std::cout << "sample 2 -> "
              << calculateScore({"jump", "add", "add"}, {3, 1, 1}) << "\n";

    std::cout << "sample 3 -> "
              << calculateScore({"jump"}, {0}) << "\n";
}
