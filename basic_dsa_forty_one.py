"""
Basic DSA - Merge Two Sorted Arrays (In-place)
Given two sorted arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

This is the classic in-place merge from the end (LeetCode 88 style).
"""


def merge_sorted_arrays(nums1, m, nums2, n):
    """
    Merge nums2 into nums1 in-place. nums1 has length m+n with extra space at end.
    Time Complexity: O(m+n)
    Space Complexity: O(1)
    """
    i = m - 1
    j = n - 1
    k = m + n - 1

    while j >= 0:
        if i >= 0 and nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1

    return nums1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Two Sorted Arrays (In-place)")
    print("=" * 60)

    tests = [
        ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),
        ([1], 1, [], 0, [1]),
        ([0], 0, [1], 1, [1]),
        ([4, 5, 6, 0, 0, 0], 3, [1, 2, 3], 3, [1, 2, 3, 4, 5, 6]),
        ([-3, -1, 2, 0, 0, 0], 3, [-2, 0, 3], 3, [-3, -2, -1, 0, 2, 3]),
    ]

    for nums1, m, nums2, n, expected in tests:
        original = nums1[:]
        merge_sorted_arrays(nums1, m, nums2, n)
        print(f"nums1={original}, nums2={nums2} -> {nums1} (expected {expected})")

