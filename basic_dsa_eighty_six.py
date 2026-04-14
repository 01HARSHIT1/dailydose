"""
Basic DSA - Top K Frequent Elements
Return the k most frequent elements.
"""

from collections import Counter


def top_k_frequent(nums, k):
    """
    Count frequencies then take k most common.
    Time Complexity: O(n log n) worst case (sorting by frequency inside most_common)
    Space Complexity: O(n)
    """
    return [x for x, _ in Counter(nums).most_common(k)]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Top K Frequent Elements")
    print("=" * 60)

    print(top_k_frequent([1, 1, 1, 2, 2, 3], 2))  # [1, 2]
    print(top_k_frequent([1], 1))  # [1]

