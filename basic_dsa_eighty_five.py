"""
Basic DSA - Kth Largest Element in an Array
Return the kth largest element in the array.
"""

import heapq


def kth_largest(nums, k):
    """
    Maintain a min-heap of size k.
    Time Complexity: O(n log k)
    Space Complexity: O(k)
    """
    heap = []
    for x in nums:
        if len(heap) < k:
            heapq.heappush(heap, x)
        else:
            if x > heap[0]:
                heapq.heapreplace(heap, x)
    return heap[0] if heap else None


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Kth Largest Element in an Array")
    print("=" * 60)

    print(kth_largest([3, 2, 1, 5, 6, 4], 2))  # 5
    print(kth_largest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))  # 4

