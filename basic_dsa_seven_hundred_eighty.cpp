/**
 * Basic DSA - Unit Conversion I (LeetCode 3528)
 * BFS from unit 0 along conversion edges, multiplying factors modulo 1e9+7.
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> baseUnitConversions(
    const std::vector<std::vector<int>>& conversions) {
    static constexpr int kMod = 1'000'000'007;

    const int unitCount = static_cast<int>(conversions.size()) + 1;
    std::vector<int> answer(unitCount, 0);
    std::vector<std::vector<std::pair<int, int>>> graph(unitCount);

    for (const std::vector<int>& conversion : conversions) {
        const int source = conversion[0];
        const int target = conversion[1];
        const int factor = conversion[2];
        graph[source].emplace_back(target, factor);
    }

    answer[0] = 1;
    std::queue<int> pending;
    pending.push(0);

    while (!pending.empty()) {
        const int source = pending.front();
        pending.pop();

        for (const auto& edge : graph[source]) {
            const int target = edge.first;
            const int factor = edge.second;
            answer[target] =
                static_cast<int>((1LL * answer[source] * factor) % kMod);
            pending.push(target);
        }
    }

    return answer;
}

void printConversions(const std::vector<int>& values) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << values[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unit Conversion I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printConversions(baseUnitConversions({{0, 1, 2}, {1, 2, 3}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printConversions(baseUnitConversions(
        {{0, 1, 2}, {0, 2, 3}, {1, 3, 4}, {1, 4, 5}, {2, 5, 2}, {4, 6, 3},
         {5, 7, 4}}));
    std::cout << "\n";
}
