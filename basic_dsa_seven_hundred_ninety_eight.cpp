/**
 * Basic DSA - Maximum Sum of Edge Values in a Graph (LeetCode 3547)
 * Greedy value assignment on degree-2-bounded connected components.
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

long long calculateComponentScore(int leftValue, int rightValue, bool isCycle) {
    std::deque<long long> window = {rightValue, rightValue};
    long long score = 0;

    for (int value = rightValue - 1; value >= leftValue; --value) {
        const long long windowValue = window.front();
        window.pop_front();
        score += windowValue * value;
        window.push_back(value);
    }

    if (isCycle)
        score += window.front() * window.back();

    return score;
}

std::vector<int> collectComponent(const std::vector<std::vector<int>>& graph,
                                  int startNode, std::vector<bool>& visited) {
    std::vector<int> component = {startNode};
    visited[startNode] = true;

    for (int index = 0; index < static_cast<int>(component.size()); ++index) {
        const int node = component[index];
        for (const int neighbor : graph[node]) {
            if (visited[neighbor])
                continue;
            visited[neighbor] = true;
            component.push_back(neighbor);
        }
    }

    return component;
}

bool isAllDegreeTwo(const std::vector<std::vector<int>>& graph,
                    const std::vector<int>& component) {
    for (const int node : component) {
        if (static_cast<int>(graph[node].size()) != 2)
            return false;
    }
    return true;
}

long long maxEdgeValueScore(int nodeCount, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> graph(nodeCount);
    std::vector<bool> visited(nodeCount, false);
    std::vector<int> cycleSizes;
    std::vector<int> pathSizes;
    int remainingValues = nodeCount;
    long long totalScore = 0;

    for (const std::vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    for (int node = 0; node < nodeCount; ++node) {
        if (visited[node])
            continue;

        const std::vector<int> component = collectComponent(graph, node, visited);
        if (static_cast<int>(component.size()) == 1)
            continue;

        if (isAllDegreeTwo(graph, component))
            cycleSizes.push_back(static_cast<int>(component.size()));
        else
            pathSizes.push_back(static_cast<int>(component.size()));
    }

    for (const int cycleSize : cycleSizes) {
        totalScore += calculateComponentScore(remainingValues - cycleSize + 1,
                                              remainingValues, true);
        remainingValues -= cycleSize;
    }

    std::sort(pathSizes.begin(), pathSizes.end(), std::greater<int>());

    for (const int pathSize : pathSizes) {
        totalScore += calculateComponentScore(remainingValues - pathSize + 1,
                                              remainingValues, false);
        remainingValues -= pathSize;
    }

    return totalScore;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Sum of Edge Values in a Graph\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxEdgeValueScore(4, {{0, 1}, {1, 2}, {2, 3}}) << "\n";

    std::cout << "sample 2 -> "
              << maxEdgeValueScore(6, {{0, 3}, {4, 5}, {2, 0}, {1, 3}, {2, 4},
                                     {1, 5}})
              << "\n";
}
