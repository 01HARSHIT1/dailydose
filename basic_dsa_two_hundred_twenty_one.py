"""
Basic DSA - Search in Rotated Sorted Array
Given an integer array nums sorted in ascending order (distinct values) then rotated,
and an integer target, return the index of target if it exists, otherwise -1.
"""


def search_rotated(nums, target):
    """
    Binary search using the sorted half property.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(nums) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if nums[mid] == target:
            return mid

        if nums[lo] <= nums[mid]:
            if nums[lo] <= target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:
            if nums[mid] < target <= nums[hi]:
                lo = mid + 1
            else:
                hi = mid - 1
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search in Rotated Sorted Array")
    print("=" * 60)

    print(search_rotated([4, 5, 6, 7, 0, 1, 2], 0))  # 4
    print(search_rotated([4, 5, 6, 7, 0, 1, 2], 3))  # -1
    print(search_rotated([1], 0))  # -1
