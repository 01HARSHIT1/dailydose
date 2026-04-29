"""
Basic DSA - Minimum Height Trees
Given an undirected tree with n nodes labeled 0..n-1 and edges,
return all roots of Minimum Height Trees.
"""

from collections import deque


def find_min_height_trees(n, edges):
    """
    Topological trimming of leaves until 1-2 centers remain.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if n == 1:
        return [0]

    graph = [set() for _ in range(n)]
    for a, b in edges:
        graph[a].add(b)
        graph[b].add(a)

    leaves = deque(i for i in range(n) if len(graph[i]) == 1)
    remaining = n

    while remaining > 2:
        layer_size = len(leaves)
        remaining -= layer_size
        for _ in range(layer_size):
            leaf = leaves.popleft()
            nei = graph[leaf].pop()
            graph[nei].remove(leaf)
            if len(graph[nei]) == 1:
                leaves.append(nei)

    return list(leaves)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Height Trees")
    print("=" * 60)

    print(sorted(find_min_height_trees(4, [[1, 0], [1, 2], [1, 3]])))  # [1]
    print(sorted(find_min_height_trees(6, [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]])))  # [3,4]
