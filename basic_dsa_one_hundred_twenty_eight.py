"""
Basic DSA - Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray of which the sum is at least target.
If there is no such subarray, return 0.
"""


def min_subarray_len(target, nums):
    """
    Sliding window (positive integers).
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left = 0
    total = 0
    best = float("inf")

    for right, x in enumerate(nums):
        total += x
        while total >= target:
            best = min(best, right - left + 1)
            total -= nums[left]
            left += 1

    return 0 if best == float("inf") else best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Size Subarray Sum")
    print("=" * 60)

    print(min_subarray_len(7, [2, 3, 1, 2, 4, 3]))  # 2
    print(min_subarray_len(4, [1, 4, 4]))  # 1
    print(min_subarray_len(11, [1, 1, 1, 1, 1, 1, 1, 1]))  # 0

