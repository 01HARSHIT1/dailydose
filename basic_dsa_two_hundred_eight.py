"""
Basic DSA - Find Pivot Index
The pivot index is the index where the sum of all the numbers strictly to the left
of the index is equal to the sum of all the numbers strictly to the right.
Return the leftmost pivot index; if none, return -1.
"""


def pivot_index(nums):
    """
    Maintain left sum; right sum = total - left - current.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    total = sum(nums)
    left = 0
    for i, x in enumerate(nums):
        if left == total - left - x:
            return i
        left += x
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Pivot Index")
    print("=" * 60)

    print(pivot_index([1, 7, 3, 6, 5, 6]))  # 3
    print(pivot_index([1, 2, 3]))  # -1
    print(pivot_index([2, 1, -1]))  # 0
