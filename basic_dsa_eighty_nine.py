"""
Basic DSA - Binary Search (Iterative)
Search for a target in a sorted list and return its index, or -1 if not found.
"""


def binary_search(nums, target):
    """
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Search (Iterative)")
    print("=" * 60)

    nums = [-1, 0, 3, 5, 9, 12]
    print(binary_search(nums, 9))   # 4
    print(binary_search(nums, 2))   # -1

