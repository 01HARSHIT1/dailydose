"""
Basic DSA - Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting
and ending position of a given target value. If target is not found, return [-1, -1].
"""


def _lower_bound(nums, target):
    lo, hi = 0, len(nums)
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    return lo


def _upper_bound(nums, target):
    lo, hi = 0, len(nums)
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] <= target:
            lo = mid + 1
        else:
            hi = mid
    return lo


def search_range(nums, target):
    """
    Two binary searches: lower bound and upper bound.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left = _lower_bound(nums, target)
    right = _upper_bound(nums, target) - 1
    if left <= right and left < len(nums) and nums[left] == target:
        return [left, right]
    return [-1, -1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find First and Last Position")
    print("=" * 60)

    print(search_range([5, 7, 7, 8, 8, 10], 8))  # [3, 4]
    print(search_range([5, 7, 7, 8, 8, 10], 6))  # [-1, -1]
    print(search_range([], 0))  # [-1, -1]
