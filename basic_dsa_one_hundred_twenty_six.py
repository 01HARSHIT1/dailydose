"""
Basic DSA - Search in Rotated Sorted Array
Given a rotated sorted array of unique integers, return the index of target, or -1 if not found.
"""


def search(nums, target):
    """
    Binary search with rotation-aware checks.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid

        # Left half sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            # Right half sorted
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search in Rotated Sorted Array")
    print("=" * 60)

    nums = [4, 5, 6, 7, 0, 1, 2]
    print(search(nums, 0))   # 4
    print(search(nums, 3))   # -1
    print(search([1], 1))    # 0

