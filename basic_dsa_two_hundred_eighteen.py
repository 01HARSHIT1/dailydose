"""
Basic DSA - Find the Difference of Two Arrays
Given two integer arrays nums1 and nums2, return an array answer of size 2 where:
- answer[0] contains all distinct integers in nums1 not present in nums2
- answer[1] contains all distinct integers in nums2 not present in nums1
"""


def find_difference(nums1, nums2):
    """
    Use set difference.
    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
    """
    s1 = set(nums1)
    s2 = set(nums2)
    return [list(s1 - s2), list(s2 - s1)]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find the Difference of Two Arrays")
    print("=" * 60)

    # Output order may vary; we sort for stable demo.
    a0, a1 = find_difference([1, 2, 3], [2, 4, 6])
    print([sorted(a0), sorted(a1)])  # [[1, 3], [4, 6]]

    b0, b1 = find_difference([1, 2, 3, 3], [1, 1, 2, 2])
    print([sorted(b0), sorted(b1)])  # [[3], []]
