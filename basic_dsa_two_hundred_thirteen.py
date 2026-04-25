"""
Basic DSA - Maximum Product Subarray
Given an integer array nums, find a contiguous non-empty subarray within nums that
has the largest product, and return the product.
"""


def max_product(nums):
    """
    Track max/min product ending at current position (min handles negative flips).
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    best = nums[0]
    cur_max = nums[0]
    cur_min = nums[0]
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

    print(max_product([2, 3, -2, 4]))  # 6
    print(max_product([-2, 0, -1]))  # 0
