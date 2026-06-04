/**
 * Basic DSA - Path Existence Queries in a Graph I (LeetCode 3532)
 * On sorted values, split into contiguous components when adjacent gap exceeds maxDiff.
 */

#include <iostream>
#include <vector>

std::vector<bool> pathExistenceQueries(
    int /*nodeCount*/, const std::vector<int>& values, int maxDiff,
    const std::vector<std::vector<int>>& queries) {
    const int count = static_cast<int>(values.size());
    std::vector<int> componentId(count);

    int currentComponent = 0;
    componentId[0] = 0;
    for (int index = 1; index < count; ++index) {
        if (values[index] - values[index - 1] > maxDiff)
            ++currentComponent;
        componentId[index] = currentComponent;
    }

    std::vector<bool> answers;
    answers.reserve(queries.size());
    for (const std::vector<int>& query : queries)
        answers.push_back(componentId[query[0]] == componentId[query[1]]);

    return answers;
}

void printAnswers(const std::vector<bool>& answers) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(answers.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << (answers[index] ? "true" : "false");
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Path Existence Queries in a Graph I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAnswers(pathExistenceQueries(2, {1, 3}, 1, {{0, 0}, {0, 1}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAnswers(pathExistenceQueries(4, {2, 5, 6, 8}, 2,
                                      {{0, 1}, {0, 2}, {1, 3}, {2, 3}}));
    std::cout << "\n";
}
