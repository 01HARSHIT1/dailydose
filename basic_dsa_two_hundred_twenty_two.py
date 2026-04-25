"""
Basic DSA - Search a 2D Matrix
You are given an m x n integer matrix with:
- Each row sorted left to right
- First integer of each row greater than last integer of previous row
Return True if target is in matrix, else False.
"""


def search_matrix(matrix, target):
    """
    Treat matrix as a flattened sorted array.
    Time Complexity: O(log(m*n))
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return False
    m, n = len(matrix), len(matrix[0])
    lo, hi = 0, m * n - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        r, c = divmod(mid, n)
        val = matrix[r][c]
        if val == target:
            return True
        if val < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search a 2D Matrix")
    print("=" * 60)

    mat = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    print(search_matrix(mat, 3))  # True
    print(search_matrix(mat, 13))  # False
