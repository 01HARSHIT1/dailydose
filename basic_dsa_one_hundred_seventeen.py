"""
Basic DSA - Rotting Oranges
Given a grid where:
- 0 = empty cell
- 1 = fresh orange
- 2 = rotten orange
Each minute, fresh oranges adjacent (4-dir) to rotten oranges become rotten.
Return the minimum number of minutes until no fresh oranges remain, or -1 if impossible.
"""

from collections import deque


def oranges_rotting(grid):
    """
    Multi-source BFS from all rotten oranges.
    Time Complexity: O(rows * cols)
    Space Complexity: O(rows * cols)
    """
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])
    q = deque()
    fresh = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 2:
                q.append((r, c))
            elif grid[r][c] == 1:
                fresh += 1

    minutes = 0
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    while q and fresh > 0:
        for _ in range(len(q)):
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    q.append((nr, nc))
        minutes += 1

    return minutes if fresh == 0 else -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotting Oranges")
    print("=" * 60)

    tests = [
        ([[2, 1, 1], [1, 1, 0], [0, 1, 1]], 4),
        ([[2, 1, 1], [0, 1, 1], [1, 0, 1]], -1),
        ([[0, 2]], 0),
        ([[1]], -1),
    ]

    for g, expected in tests:
        grid = [row[:] for row in g]
        got = oranges_rotting(grid)
        print(f"grid={g} -> {got} (expected {expected})")

