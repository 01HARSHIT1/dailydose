"""
Basic DSA - Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.
"""


def spiral_order(matrix):
    """
    Peel layers (top row, right col, bottom row, left col).
    Time Complexity: O(m*n)
    Space Complexity: O(1) extra (output excluded)
    """
    if not matrix or not matrix[0]:
        return []
    top, bottom = 0, len(matrix) - 1
    left, right = 0, len(matrix[0]) - 1
    out = []

    while top <= bottom and left <= right:
        for c in range(left, right + 1):
            out.append(matrix[top][c])
        top += 1

        for r in range(top, bottom + 1):
            out.append(matrix[r][right])
        right -= 1

        if top <= bottom:
            for c in range(right, left - 1, -1):
                out.append(matrix[bottom][c])
            bottom -= 1

        if left <= right:
            for r in range(bottom, top - 1, -1):
                out.append(matrix[r][left])
            left += 1

    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Spiral Matrix")
    print("=" * 60)

    print(spiral_order([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))  # [1,2,3,6,9,8,7,4,5]
    print(spiral_order([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))  # [1,2,3,4,8,12,11,10,9,5,6,7]
