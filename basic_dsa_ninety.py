"""
Basic DSA - Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
"""


def max_product(nums):
    """
    Track both max and min products ending at each position (min matters due to negatives).
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0

    cur_max = cur_min = best = nums[0]
    for x in nums[1:]:
        if x < 0:
            cur_max, cur_min = cur_min, cur_max
        cur_max = max(x, cur_max * x)
        cur_min = min(x, cur_min * x)
        best = max(best, cur_max)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Maximum Product Subarray")
    print("=" * 60)

    tests = [
        ([2, 3, -2, 4], 6),
        ([-2, 0, -1], 0),
        ([-2, 3, -4], 24),
        ([0, 2], 2),
        ([2], 2),
        ([], 0),
    ]

    for nums, expected in tests:
        got = max_product(nums)
        print(f"nums={nums} -> {got} (expected {expected})")

