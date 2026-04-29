"""
Basic DSA - Number of Islands II
You are given an empty 2D grid of size m x n initially filled with water.
Positions are added as land one by one. Return the number of islands after each add.
"""


def num_islands2(m, n, positions):
    """
    Union-Find (Disjoint Set Union) with path compression + union by rank.
    Time Complexity: O(k * alpha(m*n)) where k = len(positions)
    Space Complexity: O(m*n)
    """
    parent = {}
    rank = {}
    land = set()
    count = 0
    out = []

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra == rb:
            return 0
        if rank[ra] < rank[rb]:
            ra, rb = rb, ra
        parent[rb] = ra
        if rank[ra] == rank[rb]:
            rank[ra] += 1
        return 1

    for r, c in positions:
        cell = (r, c)
        if cell in land:
            out.append(count)
            continue
        land.add(cell)
        parent[cell] = cell
        rank[cell] = 0
        count += 1

        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nr, nc = r + dr, c + dc
            nei = (nr, nc)
            if 0 <= nr < m and 0 <= nc < n and nei in land:
                count -= union(cell, nei)

        out.append(count)

    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Number of Islands II")
    print("=" * 60)

    print(num_islands2(3, 3, [[0, 0], [0, 1], [1, 2], [2, 1], [1, 1]]))  # [1,1,2,3,1]
    print(num_islands2(1, 1, [[0, 0]]))  # [1]
