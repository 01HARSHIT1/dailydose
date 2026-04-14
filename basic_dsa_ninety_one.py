"""
Basic DSA - Longest Increasing Subsequence (LIS)
Return the length of the longest strictly increasing subsequence.
"""


def length_of_lis(nums):
    """
    Patience sorting idea: tails[i] is the smallest possible tail of an LIS of length i+1.
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    """
    tails = []

    def lower_bound(arr, x):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if arr[mid] < x:
                lo = mid + 1
            else:
                hi = mid
        return lo

    for x in nums:
        i = lower_bound(tails, x)
        if i == len(tails):
            tails.append(x)
        else:
            tails[i] = x
    return len(tails)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Increasing Subsequence (LIS)")
    print("=" * 60)

    tests = [
        ([10, 9, 2, 5, 3, 7, 101, 18], 4),
        ([0, 1, 0, 3, 2, 3], 4),
        ([7, 7, 7, 7, 7, 7, 7], 1),
        ([], 0),
        ([1], 1),
    ]

    for nums, expected in tests:
        got = length_of_lis(nums)
        print(f"nums={nums} -> {got} (expected {expected})")

