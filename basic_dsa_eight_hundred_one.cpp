/**
 * Basic DSA - Path Existence Queries in a Graph II (LeetCode 3534)
 * Binary lifting on value-sorted nodes for shortest path distances.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

int minJumps(const std::vector<std::vector<int>>& jump, int start, int end,
             int level) {
    if (start == end)
        return 0;
    if (jump[start][0] >= end)
        return 1;
    if (jump[start][level] < end)
        return INT_MAX;

    int jumpLevel = level;
    for (; jumpLevel >= 0; --jumpLevel) {
        if (jump[start][jumpLevel] < end)
            break;
    }

    return (1 << jumpLevel) +
           minJumps(jump, jump[start][jumpLevel], end, jumpLevel);
}

std::vector<int> pathExistenceQueries(int nodeCount, std::vector<int> values,
                                      int maxDiff,
                                      const std::vector<std::vector<int>>& queries) {
    std::vector<int> answers;
    std::vector<int> sortedValues;
    std::vector<int> indexMap(nodeCount);
    std::vector<std::pair<int, int>> valueAndIndex;

    for (int index = 0; index < nodeCount; ++index)
        valueAndIndex.emplace_back(values[index], index);

    std::sort(valueAndIndex.begin(), valueAndIndex.end());

    for (int index = 0; index < nodeCount; ++index) {
        sortedValues.push_back(valueAndIndex[index].first);
        indexMap[valueAndIndex[index].second] = index;
    }

    int maxLevel = 0;
    for (int temp = nodeCount; temp > 0; temp >>= 1)
        ++maxLevel;
    ++maxLevel;

    std::vector<std::vector<int>> jump(nodeCount, std::vector<int>(maxLevel));
    int rightIndex = 0;

    for (int leftIndex = 0; leftIndex < nodeCount; ++leftIndex) {
        while (rightIndex + 1 < nodeCount &&
               sortedValues[rightIndex + 1] - sortedValues[leftIndex] <= maxDiff) {
            ++rightIndex;
        }
        jump[leftIndex][0] = rightIndex;
    }

    for (int level = 1; level < maxLevel; ++level) {
        for (int index = 0; index < nodeCount; ++index) {
            const int previousJump = jump[index][level - 1];
            jump[index][level] = jump[previousJump][level - 1];
        }
    }

    for (const std::vector<int>& query : queries) {
        const int startNode = query[0];
        const int endNode = query[1];
        const int startIndex = std::min(indexMap[startNode], indexMap[endNode]);
        const int endIndex = std::max(indexMap[startNode], indexMap[endNode]);
        const int distance =
            minJumps(jump, startIndex, endIndex, maxLevel - 1);
        answers.push_back(distance == INT_MAX ? -1 : distance);
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
    std::cout << "Problem: Path Existence Queries in a Graph II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAnswers(pathExistenceQueries(5, {1, 8, 3, 4, 2}, 3, {{0, 3}, {2, 4}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAnswers(pathExistenceQueries(5, {5, 3, 1, 9, 10}, 2,
                                        {{0, 1}, {0, 2}, {2, 3}, {4, 3}}));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printAnswers(pathExistenceQueries(3, {3, 6, 1}, 1, {{0, 0}, {0, 1}, {1, 2}}));
    std::cout << "\n";
}
