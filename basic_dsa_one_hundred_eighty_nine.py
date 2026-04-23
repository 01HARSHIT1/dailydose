"""
Basic DSA - Pascal's Triangle II
Given an integer row_index, return the row_index-th (0-indexed) row of Pascal's triangle.
"""


def get_row(row_index):
    """
    Build the row in-place from right to left.
    Time Complexity: O(row_index^2)
    Space Complexity: O(row_index)
    """
    row = [0] * (row_index + 1)
    row[0] = 1
    for i in range(1, row_index + 1):
        for j in range(i, 0, -1):
            row[j] += row[j - 1]
    return row


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Pascal's Triangle II")
    print("=" * 60)

    print(get_row(0))  # [1]
    print(get_row(3))  # [1, 3, 3, 1]
