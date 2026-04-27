"""
Basic DSA - Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.
"""


def subarray_sum(nums, k):
    """
    Prefix sum + hashmap of counts.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    count = 0
    pref = 0
    seen = {0: 1}
    for x in nums:
        pref += x
        count += seen.get(pref - k, 0)
        seen[pref] = seen.get(pref, 0) + 1
    return count


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Subarray Sum Equals K")
    print("=" * 60)

    print(subarray_sum([1, 1, 1], 2))  # 2
    print(subarray_sum([1, 2, 3], 3))  # 2
