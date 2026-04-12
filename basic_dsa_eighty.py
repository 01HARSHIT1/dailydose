"""
Basic DSA - Unique Paths
In an m x n grid, count paths from the top-left to the bottom-right moving only right or down.
"""


def unique_paths(m, n):
    """
    One-row DP: ways to reach column j on current row.
    Time Complexity: O(m * n)
    Space Complexity: O(n)
    """
    if m <= 0 or n <= 0:
        return 0
    row = [1] * n
    for _ in range(m - 1):
        for j in range(1, n):
            row[j] += row[j - 1]
    return row[-1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Unique Paths")
    print("=" * 60)

    tests = [
        (3, 7, 28),
        (3, 2, 3),
        (1, 1, 1),
        (1, 5, 1),
    ]

    for m, n, expected in tests:
        got = unique_paths(m, n)
        print(f"m={m}, n={n} -> {got} (expected {expected})")
