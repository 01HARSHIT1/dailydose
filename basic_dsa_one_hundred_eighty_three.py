"""
Basic DSA - Search Insert Position
Given a sorted array of distinct integers nums and a target value, return the index
if the target is found. If not, return the index where it would be inserted in order.
"""


def search_insert(nums, target):
    """
    Lower bound binary search (first index with nums[i] >= target).
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(nums)
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    return lo


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Search Insert Position")
    print("=" * 60)

    print(search_insert([1, 3, 5, 6], 5))  # 2
    print(search_insert([1, 3, 5, 6], 2))  # 1
    print(search_insert([1, 3, 5, 6], 7))  # 4
    print(search_insert([1, 3, 5, 6], 0))  # 0
