"""
Basic DSA - Maximum Subarray Sum (Kadane's Algorithm)
Find the contiguous subarray with the largest sum.
"""


def max_subarray_sum(nums):
    """
    Kadane's algorithm.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0

    best = current = nums[0]
    for x in nums[1:]:
        current = max(x, current + x)
        best = max(best, current)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Maximum Subarray Sum (Kadane's Algorithm)")
    print("=" * 60)

    tests = [
        ([-2, 1, -3, 4, -1, 2, 1, -5, 4], 6),
        ([1], 1),
        ([5, 4, -1, 7, 8], 23),
        ([-1, -2, -3], -1),
        ([], 0),
    ]

    for nums, expected in tests:
        got = max_subarray_sum(nums)
        print(f"nums={nums} -> {got} (expected {expected})")

