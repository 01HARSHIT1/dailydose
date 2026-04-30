"""
Basic DSA - Find Median from Data Stream
Design a data structure that supports:
- add_num(num): add an integer
- find_median(): return median of all inserted numbers
"""

import heapq


class MedianFinder:
    """
    Two heaps:
    - low: max-heap (implemented as negatives) for the smaller half
    - high: min-heap for the larger half

    Invariant:
    - len(low) == len(high) or len(low) == len(high) + 1
    - all(low) <= all(high)

    add_num: O(log n)
    find_median: O(1)
    Space: O(n)
    """

    def __init__(self):
        self.low = []   # max-heap via negatives
        self.high = []  # min-heap

    def add_num(self, num):
        if not self.low or num <= -self.low[0]:
            heapq.heappush(self.low, -num)
        else:
            heapq.heappush(self.high, num)

        # rebalance sizes
        if len(self.low) > len(self.high) + 1:
            heapq.heappush(self.high, -heapq.heappop(self.low))
        elif len(self.high) > len(self.low):
            heapq.heappush(self.low, -heapq.heappop(self.high))

    def find_median(self):
        if not self.low and not self.high:
            raise ValueError("No numbers added")

        if len(self.low) > len(self.high):
            return float(-self.low[0])
        return (-self.low[0] + self.high[0]) / 2.0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Median from Data Stream")
    print("=" * 60)

    mf = MedianFinder()
    for x in [1, 2]:
        mf.add_num(x)
    print(mf.find_median())  # 1.5
    mf.add_num(3)
    print(mf.find_median())  # 2.0

    mf2 = MedianFinder()
    for x in [5, 15, 1, 3]:
        mf2.add_num(x)
    print(mf2.find_median())  # (3+5)/2 = 4.0
