"""
Basic DSA - Search Insert Position
Given a sorted array of distinct integers and a target, return the index if target is found.
If not, return the index where it would be inserted in order.
"""


def search_insert(nums, target):
    """
    Binary search for lower_bound (first index i with nums[i] >= target).
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums)
    while left < right:
        mid = left + (right - left) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid
    return left


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search Insert Position")
    print("=" * 60)

    tests = [
        ([1, 3, 5, 6], 5, 2),
        ([1, 3, 5, 6], 2, 1),
        ([1, 3, 5, 6], 7, 4),
        ([1, 3, 5, 6], 0, 0),
        ([1], 0, 0),
        ([1], 1, 0),
    ]

    for nums, target, expected in tests:
        got = search_insert(nums, target)
        print(f"nums={nums}, target={target} -> {got} (expected {expected})")
