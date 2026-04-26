"""
Basic DSA - Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
clockwise in-place.
"""


def rotate_image(matrix):
    """
    Transpose then reverse each row.
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    n = len(matrix)
    for r in range(n):
        for c in range(r + 1, n):
            matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]
    for r in range(n):
        matrix[r].reverse()
    return matrix


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotate Image")
    print("=" * 60)

    a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    rotate_image(a)
    print(a)  # [[7,4,1],[8,5,2],[9,6,3]]

    b = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    rotate_image(b)
    print(b)  # [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
