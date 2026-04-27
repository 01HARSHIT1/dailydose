"""
Basic DSA - Set Matrix Zeroes
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
"""


def set_zeroes(matrix):
    """
    Use first row/col as markers.
    Time Complexity: O(m*n)
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return matrix

    m, n = len(matrix), len(matrix[0])
    first_row_zero = any(matrix[0][c] == 0 for c in range(n))
    first_col_zero = any(matrix[r][0] == 0 for r in range(m))

    for r in range(1, m):
        for c in range(1, n):
            if matrix[r][c] == 0:
                matrix[r][0] = 0
                matrix[0][c] = 0

    for r in range(1, m):
        if matrix[r][0] == 0:
            for c in range(1, n):
                matrix[r][c] = 0

    for c in range(1, n):
        if matrix[0][c] == 0:
            for r in range(1, m):
                matrix[r][c] = 0

    if first_row_zero:
        for c in range(n):
            matrix[0][c] = 0
    if first_col_zero:
        for r in range(m):
            matrix[r][0] = 0

    return matrix


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Set Matrix Zeroes")
    print("=" * 60)

    a = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    set_zeroes(a)
    print(a)  # [[1,0,1],[0,0,0],[1,0,1]]

    b = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    set_zeroes(b)
    print(b)  # [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
