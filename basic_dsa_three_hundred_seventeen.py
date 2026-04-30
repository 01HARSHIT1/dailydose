"""
Basic DSA - Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements.
The answer can be returned in any order.
"""


def top_k_frequent(nums, k):
    """
    Bucket-sort by frequency.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if k <= 0:
        return []
    if not nums:
        return []

    freq = {}
    for x in nums:
        freq[x] = freq.get(x, 0) + 1

    # buckets[f] holds all values with frequency f
    buckets = [[] for _ in range(len(nums) + 1)]
    for val, f in freq.items():
        buckets[f].append(val)

    res = []
    for f in range(len(buckets) - 1, 0, -1):
        if buckets[f]:
            res.extend(buckets[f])
            if len(res) >= k:
                return res[:k]
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Top K Frequent Elements")
    print("=" * 60)

    print(sorted(top_k_frequent([1, 1, 1, 2, 2, 3], 2)))  # [1, 2]
    print(sorted(top_k_frequent([1], 1)))  # [1]
    print(sorted(top_k_frequent([4, 4, 4, 5, 6, 6], 2)))  # [4, 6]
