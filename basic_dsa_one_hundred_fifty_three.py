"""
Basic DSA - Intersection of Two Arrays
Return an array of unique elements present in both nums1 and nums2.
"""


def intersection(nums1, nums2):
    """
    Use set intersection to ensure uniqueness.
    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
    """
    return list(set(nums1) & set(nums2))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Intersection of Two Arrays")
    print("=" * 60)

    print(sorted(intersection([1, 2, 2, 1], [2, 2])))  # [2]
    print(sorted(intersection([4, 9, 5], [9, 4, 9, 8, 4])))  # [4, 9]
