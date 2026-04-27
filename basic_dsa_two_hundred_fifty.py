"""
Basic DSA - Longest Increasing Subsequence (LIS)
Given an integer array nums, return the length of the longest strictly increasing subsequence.
"""


def length_of_lis(nums):
    """
    Patience sorting with binary search on tails.
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    """
    tails = []
    for x in nums:
        lo, hi = 0, len(tails)
        while lo < hi:
            mid = (lo + hi) // 2
            if tails[mid] < x:
                lo = mid + 1
            else:
                hi = mid
        if lo == len(tails):
            tails.append(x)
        else:
            tails[lo] = x
    return len(tails)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Increasing Subsequence (LIS)")
    print("=" * 60)

    print(length_of_lis([10, 9, 2, 5, 3, 7, 101, 18]))  # 4
    print(length_of_lis([0, 1, 0, 3, 2, 3]))  # 4
