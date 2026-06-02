/**
 * Basic DSA - Properties Graph (LeetCode 3493)
 * Union nodes when property arrays share at least k distinct values.
 */

#include <iostream>
#include <numeric>
#include <set>
#include <vector>

class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
    int components;

public:
    explicit UnionFind(int size) : parent(size), rank(size), components(size) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unite(int first, int second) {
        first = find(first);
        second = find(second);
        if (first == second)
            return;

        if (rank[first] < rank[second])
            std::swap(first, second);

        parent[second] = first;
        if (rank[first] == rank[second])
            rank[first]++;
        components--;
    }

    int count() const { return components; }
};

int intersectionSize(const std::set<int>& left, const std::set<int>& right) {
    int shared = 0;
    for (int value : left) {
        if (right.count(value))
            shared++;
    }
    return shared;
}

int numberOfComponents(const std::vector<std::vector<int>>& properties, int k) {
    const int n = static_cast<int>(properties.size());
    UnionFind unionFind(n);
    std::vector<std::set<int>> propertySets(n);

    for (int i = 0; i < n; ++i)
        propertySets[i] = std::set<int>(properties[i].begin(), properties[i].end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersectionSize(propertySets[i], propertySets[j]) >= k)
                unionFind.unite(i, j);
        }
    }

    return unionFind.count();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Properties Graph\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << numberOfComponents({{1, 2}, {1, 1}, {3, 4}, {4, 5}, {5, 6}, {7, 7}}, 1)
              << "\n";

    std::cout << "sample 2 -> "
              << numberOfComponents({{1, 2, 3}, {2, 3, 4}, {4, 3, 5}}, 2) << "\n";

    std::cout << "sample 3 -> " << numberOfComponents({{1, 1}, {1, 1}}, 2) << "\n";
}
