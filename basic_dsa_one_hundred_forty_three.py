"""
Basic DSA - Find Pivot Index
The pivot index is where the sum of elements to the left equals the sum to the right.
If no such index exists, return -1.
"""


def pivot_index(nums):
    """
    Total sum minus left sum minus current gives right sum.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    total = sum(nums)
    left_sum = 0
    for i, x in enumerate(nums):
        if left_sum == total - left_sum - x:
            return i
        left_sum += x
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Pivot Index")
    print("=" * 60)

    print(pivot_index([1, 7, 3, 6, 5, 6]))  # 3
    print(pivot_index([1, 2, 3]))  # -1
    print(pivot_index([2, 1, -1]))  # 0
