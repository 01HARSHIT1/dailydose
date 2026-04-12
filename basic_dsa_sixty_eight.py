"""
Basic DSA - Subarray Sum Equals K
Return the number of contiguous subarrays whose elements sum to k.
"""


def subarray_sum(nums, k):
    """
    Prefix sum with hash map of prefix frequency.
    If prefix[j] - prefix[i] = k, then sum(nums[i:j]) = k.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    count = 0
    prefix = 0
    seen = {0: 1}

    for x in nums:
        prefix += x
        need = prefix - k
        count += seen.get(need, 0)
        seen[prefix] = seen.get(prefix, 0) + 1

    return count


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Subarray Sum Equals K")
    print("=" * 60)

    tests = [
        ([1, 1, 1], 2, 2),
        ([1, 2, 3], 3, 2),
        ([1], 0, 0),
        ([1, -1, 0], 0, 3),
    ]

    for nums, k, expected in tests:
        got = subarray_sum(nums, k)
        print(f"nums={nums}, k={k} -> {got} (expected {expected})")
