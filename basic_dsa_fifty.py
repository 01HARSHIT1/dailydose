"""
Basic DSA - Intersection of Two Arrays
Return the unique intersection of two arrays.
"""


def intersection(nums1, nums2):
    """
    Use sets for uniqueness.
    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
    """
    return list(set(nums1) & set(nums2))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Intersection of Two Arrays")
    print("=" * 60)

    tests = [
        ([1, 2, 2, 1], [2, 2], [2]),
        ([4, 9, 5], [9, 4, 9, 8, 4], [4, 9]),
        ([], [1, 2], []),
        ([1, 1, 1], [1], [1]),
    ]

    for a, b, expected in tests:
        got = sorted(intersection(a, b))
        print(f"nums1={a}, nums2={b} -> {got} (expected {expected})")

