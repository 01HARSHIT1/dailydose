"""
Basic DSA - Search a 2D Matrix
Given an m x n matrix where each row is sorted and the first integer of each row
is greater than the last integer of the previous row, determine if target exists.
"""


def search_matrix(matrix, target):
    """
    Binary search treating matrix as a flattened sorted array.
    Time Complexity: O(log(m*n))
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return False

    rows, cols = len(matrix), len(matrix[0])
    left, right = 0, rows * cols - 1

    while left <= right:
        mid = left + (right - left) // 2
        r, c = divmod(mid, cols)
        v = matrix[r][c]
        if v == target:
            return True
        if v < target:
            left = mid + 1
        else:
            right = mid - 1

    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search a 2D Matrix")
    print("=" * 60)

    m = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    print(search_matrix(m, 3))   # True
    print(search_matrix(m, 13))  # False
    print(search_matrix([], 1))  # False

