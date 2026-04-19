"""
Basic DSA - Monotonic Array
Return True if nums is monotonically increasing or monotonically decreasing.
"""


def is_monotonic(nums):
    """
    Track whether we ever break non-decreasing or non-increasing order.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    inc = dec = True
    for i in range(1, len(nums)):
        if nums[i] < nums[i - 1]:
            inc = False
        if nums[i] > nums[i - 1]:
            dec = False
    return inc or dec


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Monotonic Array")
    print("=" * 60)

    print(is_monotonic([1, 2, 2, 3]))  # True (non-decreasing)
    print(is_monotonic([6, 5, 4, 4]))  # True (non-increasing)
    print(is_monotonic([1, 3, 2]))  # False
