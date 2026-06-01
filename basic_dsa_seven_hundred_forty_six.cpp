/**
 * Basic DSA - Fruits Into Baskets III (LeetCode 3479)
 * Place fruits using segment tree to find leftmost basket with enough capacity.
 */

#include <algorithm>
#include <iostream>
#include <vector>

struct SegmentTree {
    std::vector<int> tree;
    std::vector<int> values;
    int size;

    explicit SegmentTree(const std::vector<int>& baskets)
        : values(baskets), size(static_cast<int>(baskets.size())), tree(size * 4) {
        build(1, 1, size);
    }

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = values[left - 1];
            return;
        }
        const int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }

    void modify(int node, int left, int right, int index, int value) {
        if (left == right) {
            tree[node] = value;
            return;
        }
        const int mid = (left + right) / 2;
        if (index <= mid)
            modify(node * 2, left, mid, index, value);
        else
            modify(node * 2 + 1, mid + 1, right, index, value);
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int left, int right, int need) {
        if (tree[node] < need)
            return -1;
        if (left == right)
            return left;
        const int mid = (left + right) / 2;
        if (tree[node * 2] >= need)
            return query(node * 2, left, mid, need);
        return query(node * 2 + 1, mid + 1, right, need);
    }
};

int numOfUnplacedFruits(const std::vector<int>& fruits, std::vector<int> baskets) {
    SegmentTree tree(baskets);
    const int n = static_cast<int>(baskets.size());
    int unplaced = 0;

    for (int fruit : fruits) {
        const int basketIndex = tree.query(1, 1, n, fruit);
        if (basketIndex < 0)
            ++unplaced;
        else
            tree.modify(1, 1, n, basketIndex, 0);
    }

    return unplaced;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fruits Into Baskets III\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << numOfUnplacedFruits({4, 2, 5}, {3, 5, 4}) << "\n";
    std::cout << "sample 2 -> " << numOfUnplacedFruits({3, 6, 1}, {6, 4, 7}) << "\n";
}
