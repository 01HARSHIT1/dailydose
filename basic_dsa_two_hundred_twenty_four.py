"""
Basic DSA - Find Minimum in Rotated Sorted Array
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
Given the rotated array nums (distinct values), return the minimum element.
"""


def find_min(nums):
    """
    Binary search comparing mid with right.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] > nums[hi]:
            lo = mid + 1
        else:
            hi = mid
    return nums[lo]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Minimum in Rotated Sorted Array")
    print("=" * 60)

    print(find_min([3, 4, 5, 1, 2]))  # 1
    print(find_min([4, 5, 6, 7, 0, 1, 2]))  # 0
    print(find_min([11, 13, 15, 17]))  # 11
