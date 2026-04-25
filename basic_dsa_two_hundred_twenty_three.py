"""
Basic DSA - Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer
matrix. This matrix has the following properties:
- Integers in each row are sorted in ascending order.
- Integers in each column are sorted in ascending order.
"""


def search_matrix_ii(matrix, target):
    """
    Start from top-right and walk left/down.
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return False
    r, c = 0, len(matrix[0]) - 1
    while r < len(matrix) and c >= 0:
        val = matrix[r][c]
        if val == target:
            return True
        if val > target:
            c -= 1
        else:
            r += 1
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search a 2D Matrix II")
    print("=" * 60)

    mat = [
        [1, 4, 7, 11, 15],
        [2, 5, 8, 12, 19],
        [3, 6, 9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30],
    ]
    print(search_matrix_ii(mat, 5))  # True
    print(search_matrix_ii(mat, 20))  # False
