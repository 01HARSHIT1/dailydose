"""
Basic DSA - Contains Nearby Duplicate
Given an integer array nums and an integer k, return True if there are two distinct
indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
"""


def contains_nearby_duplicate(nums, k):
    """
    Sliding window set of last k elements.
    Time Complexity: O(n)
    Space Complexity: O(min(n, k))
    """
    window = set()
    for i, x in enumerate(nums):
        if x in window:
            return True
        window.add(x)
        if len(window) > k:
            window.remove(nums[i - k])
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Contains Nearby Duplicate")
    print("=" * 60)

    print(contains_nearby_duplicate([1, 2, 3, 1], 3))  # True
    print(contains_nearby_duplicate([1, 0, 1, 1], 1))  # True
    print(contains_nearby_duplicate([1, 2, 3, 1, 2, 3], 2))  # False
