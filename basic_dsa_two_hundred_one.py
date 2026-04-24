"""
Basic DSA - Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.
"""


def top_k_frequent(nums, k):
    """
    Bucket sort by frequency.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    freq = {}
    for x in nums:
        freq[x] = freq.get(x, 0) + 1

    buckets = [[] for _ in range(len(nums) + 1)]
    for x, f in freq.items():
        buckets[f].append(x)

    out = []
    for f in range(len(buckets) - 1, 0, -1):
        for x in buckets[f]:
            out.append(x)
            if len(out) == k:
                return out
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Top K Frequent Elements")
    print("=" * 60)

    print(sorted(top_k_frequent([1, 1, 1, 2, 2, 3], 2)))  # [1, 2]
    print(sorted(top_k_frequent([1], 1)))  # [1]
