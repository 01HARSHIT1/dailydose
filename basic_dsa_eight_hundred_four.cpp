/**
 * Basic DSA - Find X Value of Array II (LeetCode 3525)
 * Segment tree tracking remainder frequencies under updates and queries.
 */

#include <iostream>
#include <vector>

struct RemainderNode {
    int remainderCounts[5] = {0};
    int productModulo = 1;
};

class RemainderSegmentTree {
public:
    RemainderSegmentTree(const std::vector<int>& values, int modulo)
        : size(static_cast<int>(values.size())), modulo(modulo),
          tree(4 * static_cast<int>(values.size())) {
        build(values, 0, 0, size - 1);
    }

    void update(int index, int value) { update(0, 0, size - 1, index, value); }

    RemainderNode query(int left, int right) const {
        return query(0, 0, size - 1, left, right);
    }

private:
    int size;
    int modulo;
    std::vector<RemainderNode> tree;

    RemainderNode mergeNodes(const RemainderNode& left,
                             const RemainderNode& right) const {
        RemainderNode merged;
        merged.productModulo = (left.productModulo * right.productModulo) % modulo;

        for (int remainder = 0; remainder < modulo; ++remainder)
            merged.remainderCounts[remainder] = left.remainderCounts[remainder];

        for (int remainder = 0; remainder < modulo; ++remainder) {
            const int shiftedRemainder =
                (remainder * left.productModulo) % modulo;
            merged.remainderCounts[shiftedRemainder] +=
                right.remainderCounts[remainder];
        }

        return merged;
    }

    void build(const std::vector<int>& values, int nodeIndex, int left,
               int right) {
        if (left == right) {
            tree[nodeIndex].remainderCounts[values[left]] = 1;
            tree[nodeIndex].productModulo = values[left];
            return;
        }

        const int middle = (left + right) / 2;
        build(values, nodeIndex * 2 + 1, left, middle);
        build(values, nodeIndex * 2 + 2, middle + 1, right);
        tree[nodeIndex] =
            mergeNodes(tree[nodeIndex * 2 + 1], tree[nodeIndex * 2 + 2]);
    }

    void update(int nodeIndex, int left, int right, int targetIndex,
                int value) {
        if (left == right) {
            for (int remainder = 0; remainder < modulo; ++remainder)
                tree[nodeIndex].remainderCounts[remainder] = 0;
            tree[nodeIndex].remainderCounts[value] = 1;
            tree[nodeIndex].productModulo = value;
            return;
        }

        const int middle = (left + right) / 2;
        if (targetIndex <= middle)
            update(nodeIndex * 2 + 1, left, middle, targetIndex, value);
        else
            update(nodeIndex * 2 + 2, middle + 1, right, targetIndex, value);

        tree[nodeIndex] =
            mergeNodes(tree[nodeIndex * 2 + 1], tree[nodeIndex * 2 + 2]);
    }

    RemainderNode query(int nodeIndex, int left, int right, int queryLeft,
                        int queryRight) const {
        if (queryLeft <= left && right <= queryRight)
            return tree[nodeIndex];
        if (right < queryLeft || queryRight < left)
            return RemainderNode();

        const int middle = (left + right) / 2;
        return mergeNodes(query(nodeIndex * 2 + 1, left, middle, queryLeft,
                                queryRight),
                          query(nodeIndex * 2 + 2, middle + 1, right,
                                queryLeft, queryRight));
    }
};

std::vector<int> findXValueResults(std::vector<int> values, int modulo,
                                   const std::vector<std::vector<int>>& queries) {
    for (int& value : values)
        value %= modulo;

    RemainderSegmentTree segmentTree(values, modulo);
    std::vector<int> results;

    for (const std::vector<int>& query : queries) {
        const int index = query[0];
        const int newValue = query[1] % modulo;
        const int startIndex = query[2];
        const int targetRemainder = query[3];

        segmentTree.update(index, newValue);
        results.push_back(
            segmentTree.query(startIndex, static_cast<int>(values.size()) - 1)
                .remainderCounts[targetRemainder]);
    }

    return results;
}

void printResults(const std::vector<int>& results) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(results.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << results[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find X Value of Array II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printResults(findXValueResults({1, 2, 3, 4, 5}, 3,
                                   {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printResults(findXValueResults({1, 2, 4, 8, 16, 32}, 4,
                                   {{0, 2, 0, 2}, {0, 2, 0, 1}}));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printResults(findXValueResults({1, 1, 2, 1, 1}, 2, {{2, 1, 0, 1}}));
    std::cout << "\n";
}
