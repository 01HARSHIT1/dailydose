"""
Basic DSA - First Bad Version
You are given an API isBadVersion(version) which returns whether version is bad.
Given n, find the first bad version (smallest bad), minimizing calls.

This file includes a local stub for demonstration.
"""


def first_bad_version(n, is_bad_version):
    """
    Binary search for the first True.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 1, n
    while lo < hi:
        mid = (lo + hi) // 2
        if is_bad_version(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: First Bad Version")
    print("=" * 60)

    bad = 4

    def is_bad_version(v):
        return v >= bad

    print(first_bad_version(5, is_bad_version))  # 4
