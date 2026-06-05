/**
 * Basic DSA - Unit Conversion II (LeetCode 3535)
 * BFS base conversions from unit 0, then answer queries with modular inverses.
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace {
constexpr int kMod = 1'000'000'007;

long long modPow(long long base, long long exponent) {
    long long result = 1;
    base %= kMod;

    while (exponent > 0) {
        if (exponent & 1LL)
            result = result * base % kMod;
        base = base * base % kMod;
        exponent >>= 1LL;
    }

    return result;
}

std::vector<int> baseUnitConversions(
    const std::vector<std::vector<int>>& conversions) {
    const int unitCount = static_cast<int>(conversions.size()) + 1;
    std::vector<int> units(unitCount, 0);
    std::vector<std::vector<std::pair<int, int>>> graph(unitCount);

    for (const std::vector<int>& conversion : conversions) {
        const int source = conversion[0];
        const int target = conversion[1];
        const int factor = conversion[2];
        graph[source].emplace_back(target, factor);
    }

    units[0] = 1;
    std::queue<int> pending;
    pending.push(0);

    while (!pending.empty()) {
        const int source = pending.front();
        pending.pop();

        for (const auto& edge : graph[source]) {
            const int target = edge.first;
            const int factor = edge.second;
            units[target] =
                static_cast<int>((1LL * units[source] * factor) % kMod);
            pending.push(target);
        }
    }

    return units;
}
}  // namespace

std::vector<int> queryConversions(const std::vector<std::vector<int>>& conversions,
                                  const std::vector<std::vector<int>>& queries) {
    const std::vector<int> units = baseUnitConversions(conversions);
    std::vector<int> answers;
    answers.reserve(queries.size());

    for (const std::vector<int>& query : queries) {
        const int fromUnit = query[0];
        const int toUnit = query[1];
        const long long inverseFrom =
            modPow(units[fromUnit], kMod - 2);
        answers.push_back(
            static_cast<int>((1LL * units[toUnit] * inverseFrom) % kMod));
    }

    return answers;
}

void printAnswers(const std::vector<int>& answers) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(answers.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << answers[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unit Conversion II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAnswers(queryConversions({{0, 1, 2}, {0, 2, 6}}, {{1, 2}, {1, 0}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAnswers(queryConversions(
        {{0, 1, 2}, {0, 2, 6}, {0, 3, 8}, {2, 4, 2}, {2, 5, 4}, {3, 6, 3}},
        {{1, 2}, {0, 4}, {6, 5}, {4, 6}, {6, 1}}));
    std::cout << "\n";
}
