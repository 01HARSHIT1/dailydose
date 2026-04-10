"""
Basic DSA - Squares of a Sorted Array
Given an integer array sorted in non-decreasing order, return an array of the squares of each number,
also sorted in non-decreasing order.
"""


def sorted_squares(nums):
    """
    Two pointers from both ends (largest absolute values toward middle).
    Time Complexity: O(n)
    Space Complexity: O(n) for output
    """
    n = len(nums)
    result = [0] * n
    left, right = 0, n - 1
    pos = n - 1

    while left <= right:
        if abs(nums[left]) > abs(nums[right]):
            result[pos] = nums[left] * nums[left]
            left += 1
        else:
            result[pos] = nums[right] * nums[right]
            right -= 1
        pos -= 1

    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Squares of a Sorted Array")
    print("=" * 60)

    tests = [
        ([-4, -1, 0, 3, 10], [0, 1, 9, 16, 100]),
        ([-7, -3, 2, 3, 11], [4, 9, 9, 49, 121]),
        ([-1], [1]),
        ([0, 0], [0, 0]),
    ]

    for nums, expected in tests:
        got = sorted_squares(nums)
        print(f"nums={nums} -> {got} (expected {expected})")
