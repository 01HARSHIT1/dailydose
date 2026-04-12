"""
Basic DSA - Rotate Image
Rotate an n x n matrix 90 degrees clockwise in-place.
"""


def rotate(matrix):
    """
    Transpose, then reverse each row.
    Time Complexity: O(n^2)
    Space Complexity: O(1) extra
    """
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for row in matrix:
        row.reverse()
    return matrix


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotate Image (90 degrees clockwise)")
    print("=" * 60)

    m1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    e1 = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
    print(f"before={m1}")
    rotate(m1)
    print(f"after -> {m1} (expected {e1})")

    m2 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    e2 = [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]
    rotate(m2)
    print(f"4x4 -> {m2} (expected {e2})")
