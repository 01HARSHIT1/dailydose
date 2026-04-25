"""
Basic DSA - Find Peak Element
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element and return its index.
You may assume nums[-1] = nums[n] = -inf.
"""


def find_peak_element(nums):
    """
    Binary search on slope.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] < nums[mid + 1]:
            lo = mid + 1
        else:
            hi = mid
    return lo


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Peak Element")
    print("=" * 60)

    print(find_peak_element([1, 2, 3, 1]))  # 2
    print(find_peak_element([1, 2, 1, 3, 5, 6, 4]))  # 1 or 5
