"""
Basic DSA - Minimum Path Sum
Given a grid filled with non-negative numbers, find a path from top-left to bottom-right
which minimizes the sum of all numbers along its path. You can only move right or down.
"""


def min_path_sum(grid):
    """
    DP in-place on grid.
    Time Complexity: O(rows * cols)
    Space Complexity: O(1) extra (mutates grid)
    """
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])

    for r in range(rows):
        for c in range(cols):
            if r == 0 and c == 0:
                continue
            from_up = grid[r - 1][c] if r > 0 else None
            from_left = grid[r][c - 1] if c > 0 else None
            if from_up is None:
                grid[r][c] += from_left
            elif from_left is None:
                grid[r][c] += from_up
            else:
                grid[r][c] += min(from_up, from_left)

    return grid[-1][-1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Path Sum")
    print("=" * 60)

    tests = [
        ([[1, 3, 1], [1, 5, 1], [4, 2, 1]], 7),
        ([[1, 2, 3], [4, 5, 6]], 12),
        ([], 0),
    ]

    for g, expected in tests:
        grid = [row[:] for row in g]
        got = min_path_sum(grid)
        print(f"grid={g} -> {got} (expected {expected})")

