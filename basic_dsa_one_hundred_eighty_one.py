"""
Basic DSA - Binary Search
Given a sorted array of integers nums and an integer target, return the index of
target if it exists, otherwise return -1.
"""


def binary_search(nums, target):
    """
    Classic binary search.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(nums) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Search")
    print("=" * 60)

    print(binary_search([-1, 0, 3, 5, 9, 12], 9))  # 4
    print(binary_search([-1, 0, 3, 5, 9, 12], 2))  # -1
