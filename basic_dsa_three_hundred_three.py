"""
Basic DSA - Range Sum Query 2D - Immutable
Given a 2D matrix matrix, handle multiple queries:
Return the sum of elements inside rectangle defined by
(row1, col1) as top-left and (row2, col2) as bottom-right, inclusive.
"""


class NumMatrix:
    """
    2D prefix sums.
    Build: O(m*n)
    Query: O(1)
    Space: O(m*n)
    """

    def __init__(self, matrix):
        if not matrix or not matrix[0]:
            self.pref = [[0]]
            return
        m, n = len(matrix), len(matrix[0])
        self.pref = [[0] * (n + 1) for _ in range(m + 1)]
        for r in range(1, m + 1):
            row_sum = 0
            for c in range(1, n + 1):
                row_sum += matrix[r - 1][c - 1]
                self.pref[r][c] = self.pref[r - 1][c] + row_sum

    def sum_region(self, row1, col1, row2, col2):
        p = self.pref
        return (
            p[row2 + 1][col2 + 1]
            - p[row1][col2 + 1]
            - p[row2 + 1][col1]
            + p[row1][col1]
        )


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Range Sum Query 2D - Immutable")
    print("=" * 60)

    mat = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5],
    ]
    nm = NumMatrix(mat)
    print(nm.sum_region(2, 1, 4, 3))  # 8
    print(nm.sum_region(1, 1, 2, 2))  # 11
    print(nm.sum_region(1, 2, 2, 4))  # 12
