"""
Basic DSA - Maximum Subarray (Kadane's Algorithm)
Given an integer array nums, find the contiguous subarray with the largest sum and
return its sum.
"""


def max_subarray(nums):
    """
    Kadane's algorithm: best subarray ending here vs start new.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    best = nums[0]
    cur = nums[0]
    for x in nums[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Maximum Subarray")
    print("=" * 60)

    print(max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # 6
    print(max_subarray([1]))  # 1
    print(max_subarray([5, 4, -1, 7, 8]))  # 23
