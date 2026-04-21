"""
Basic DSA - Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n representing the number of elements in nums1 and nums2.

Merge nums2 into nums1 as one sorted array. nums1 has length m + n with the last n
elements set to 0 and should be overwritten in-place.
"""


def merge(nums1, m, nums2, n):
    """
    Merge from the end to avoid overwriting.
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    i, j, k = m - 1, n - 1, m + n - 1
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
    print("Problem: Merge Sorted Array")
    print("=" * 60)

    a = [1, 2, 3, 0, 0, 0]
    merge(a, 3, [2, 5, 6], 3)
    print(a)  # [1, 2, 2, 3, 5, 6]

    b = [1]
    merge(b, 1, [], 0)
    print(b)  # [1]
