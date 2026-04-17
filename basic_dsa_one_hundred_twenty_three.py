"""
Basic DSA - Find Peak Element
Given an array nums, find a peak element and return its index.
A peak element is an element that is strictly greater than its neighbors.
You may assume nums[-1] = nums[n] = -inf.
"""


def find_peak_element(nums):
    """
    Binary search on slope.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if not nums:
        return None

    left, right = 0, len(nums) - 1
    while left < right:
        mid = left + (right - left) // 2
        if nums[mid] < nums[mid + 1]:
            left = mid + 1
        else:
            right = mid
    return left


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Peak Element")
    print("=" * 60)

    tests = [
        ([1, 2, 3, 1], 2),         # peak at index 2 (value 3)
        ([1, 2, 1, 3, 5, 6, 4], 5),# one valid peak index is 5 (value 6)
        ([1], 0),
        ([2, 1], 0),
        ([1, 2], 1),
    ]

    for nums, expected in tests:
        got = find_peak_element(nums)
        print(f"nums={nums} -> peak_index={got} (expected {expected})")

