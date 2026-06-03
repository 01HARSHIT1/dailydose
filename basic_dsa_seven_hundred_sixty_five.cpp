/**
 * Basic DSA - Minimum Cost to Reach Every Position (LeetCode 3502)
 * Prefix minimum of swap costs; later free swaps use the cheapest paid step.
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> minCosts(const std::vector<int>& cost) {
    const int size = static_cast<int>(cost.size());
    std::vector<int> answer(size);
    int runningMinimum = cost[0];

    for (int index = 0; index < size; ++index) {
        runningMinimum = std::min(runningMinimum, cost[index]);
        answer[index] = runningMinimum;
    }

    return answer;
}

void printCosts(const std::vector<int>& costs) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(costs.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << costs[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Cost to Reach Every Position\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printCosts(minCosts({5, 3, 4, 1, 3, 2}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printCosts(minCosts({1, 2, 4, 6, 7}));
    std::cout << "\n";
}
