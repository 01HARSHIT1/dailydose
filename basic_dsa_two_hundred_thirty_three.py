"""
Basic DSA - Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands. An island is surrounded by water and is formed by connecting
adjacent lands horizontally or vertically.
"""


def num_islands(grid):
    """
    DFS flood fill; mutate grid to mark visited.
    Time Complexity: O(m*n)
    Space Complexity: O(m*n) worst-case recursion depth
    """
    if not grid or not grid[0]:
        return 0

    m, n = len(grid), len(grid[0])

    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != "1":
            return
        grid[r][c] = "0"
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    count = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == "1":
                count += 1
                dfs(r, c)
    return count


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Number of Islands")
    print("=" * 60)

    g1 = [
        list("11110"),
        list("11010"),
        list("11000"),
        list("00000"),
    ]
    g2 = [
        list("11000"),
        list("11000"),
        list("00100"),
        list("00011"),
    ]

    # Convert to list of list of str already via list().
    print(num_islands(g1))  # 1
    print(num_islands(g2))  # 3
