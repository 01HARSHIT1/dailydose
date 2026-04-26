"""
Basic DSA - Max Area of Island
Given an m x n binary grid, return the maximum area of an island in the grid.
An island is a group of 1's connected 4-directionally.
"""


def max_area_of_island(grid):
    """
    DFS flood fill; mutate grid to mark visited.
    Time Complexity: O(m*n)
    Space Complexity: O(m*n) worst-case recursion depth
    """
    if not grid or not grid[0]:
        return 0

    m, n = len(grid), len(grid[0])

    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != 1:
            return 0
        grid[r][c] = 0
        area = 1
        area += dfs(r + 1, c)
        area += dfs(r - 1, c)
        area += dfs(r, c + 1)
        area += dfs(r, c - 1)
        return area

    best = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == 1:
                best = max(best, dfs(r, c))
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Max Area of Island")
    print("=" * 60)

    g = [
        [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    ]
    print(max_area_of_island(g))  # 6
