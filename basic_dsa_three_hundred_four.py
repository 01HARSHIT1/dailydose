"""
Basic DSA - Num Matrix (Mutable) using 2D Binary Indexed Tree
Design a data structure that supports:
- update(row, col, val)
- sum_region(row1, col1, row2, col2)
"""


class NumMatrix:
    """
    2D Fenwick Tree (BIT).
    Build: O(m*n log m log n)
    Update: O(log m log n)
    Query: O(log m log n)
    Space: O(m*n)
    """

    def __init__(self, matrix):
        if not matrix or not matrix[0]:
            self.m = self.n = 0
            self.bit = [[0]]
            self.mat = [[]]
            return
        self.m, self.n = len(matrix), len(matrix[0])
        self.bit = [[0] * (self.n + 1) for _ in range(self.m + 1)]
        self.mat = [[0] * self.n for _ in range(self.m)]
        for r in range(self.m):
            for c in range(self.n):
                self.update(r, c, matrix[r][c])

    def _add(self, r, c, delta):
        i = r + 1
        while i <= self.m:
            j = c + 1
            while j <= self.n:
                self.bit[i][j] += delta
                j += j & -j
            i += i & -i

    def update(self, row, col, val):
        delta = val - self.mat[row][col]
        self.mat[row][col] = val
        self._add(row, col, delta)

    def _prefix_sum(self, r, c):
        s = 0
        i = r + 1
        while i > 0:
            j = c + 1
            while j > 0:
                s += self.bit[i][j]
                j -= j & -j
            i -= i & -i
        return s

    def sum_region(self, row1, col1, row2, col2):
        return (
            self._prefix_sum(row2, col2)
            - self._prefix_sum(row1 - 1, col2)
            - self._prefix_sum(row2, col1 - 1)
            + self._prefix_sum(row1 - 1, col1 - 1)
        )


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Num Matrix (Mutable)")
    print("=" * 60)

    nm = NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]])
    print(nm.sum_region(2, 1, 4, 3))  # 8
    nm.update(3, 2, 2)
    print(nm.sum_region(2, 1, 4, 3))  # 10
