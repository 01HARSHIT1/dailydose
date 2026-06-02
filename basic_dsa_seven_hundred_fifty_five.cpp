/**
 * Basic DSA - Closest Equal Element Queries (LeetCode 3488)
 * Precompute minimum circular distance to another equal element per index.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> solveQueries(const std::vector<int>& nums, const std::vector<int>& queries) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> minDistance(n, n);
    std::unordered_map<int, int> lastSeen;

    for (int i = 0; i < n * 2; ++i) {
        const int index = i % n;
        const int value = nums[index];

        const auto iterator = lastSeen.find(value);
        if (iterator != lastSeen.end()) {
            const int previousIndex = iterator->second % n;
            const int distance = i - iterator->second;
            minDistance[index] = std::min(minDistance[index], distance);
            minDistance[previousIndex] = std::min(minDistance[previousIndex], distance);
        }

        lastSeen[value] = i;
    }

    std::vector<int> answers;
    answers.reserve(queries.size());

    for (int query : queries)
        answers.push_back(minDistance[query] == n ? -1 : minDistance[query]);

    return answers;
}

void printAnswers(const std::vector<int>& answers) {
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(answers.size()); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << answers[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Closest Equal Element Queries\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAnswers(solveQueries({1, 3, 1, 4, 1, 3, 2}, {0, 3, 5}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAnswers(solveQueries({1, 2, 3, 4}, {0, 1, 2, 3}));
    std::cout << "\n";
}
