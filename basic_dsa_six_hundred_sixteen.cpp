/**
 * Basic DSA - Maximize Win From Two Segments (LeetCode 2555)
 * Two non-overlapping windows of span <= k on sorted prize positions; prefix max of prior window counts.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maximizeWin(const std::vector<int>& prizePositions, int k) {
    int answer = 0;
    std::vector<int> prefixBest(prizePositions.size(), 0);
    int left = 0;

    for (int right = 0; right < static_cast<int>(prizePositions.size()); ++right) {
        while (prizePositions[static_cast<size_t>(right)] - prizePositions[static_cast<size_t>(left)] > k)
            ++left;
        int count = right - left + 1;
        int priorBest = left > 0 ? prefixBest[static_cast<size_t>(left - 1)] : 0;
        answer = std::max(answer, count + priorBest);
        prefixBest[static_cast<size_t>(right)] =
            std::max(right > 0 ? prefixBest[static_cast<size_t>(right - 1)] : 0, count);
    }
    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Win From Two Segments\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximizeWin({1, 1, 2, 2, 3, 3, 5}, 2) << "\n";
    std::cout << "sample 2 -> " << maximizeWin({1, 2, 3, 4}, 0) << "\n";
}
