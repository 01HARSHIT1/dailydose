"""
Basic DSA - Range Sum Query - Mutable
Given an integer array nums, handle:
- update(index, val)
- sum_range(left, right)
with both operations efficient.
"""


class NumArray:
    """
    Fenwick Tree (Binary Indexed Tree).
    Build: O(n log n)
    Update: O(log n)
    Query: O(log n)
    Space: O(n)
    """

    def __init__(self, nums):
        self.n = len(nums)
        self.bit = [0] * (self.n + 1)
        self.arr = nums[:]
        for i, x in enumerate(nums):
            self._add(i + 1, x)

    def _add(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def _prefix_sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def update(self, index, val):
        delta = val - self.arr[index]
        self.arr[index] = val
        self._add(index + 1, delta)

    def sum_range(self, left, right):
        return self._prefix_sum(right + 1) - self._prefix_sum(left)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Range Sum Query - Mutable")
    print("=" * 60)

    na = NumArray([1, 3, 5])
    print(na.sum_range(0, 2))  # 9
    na.update(1, 2)
    print(na.sum_range(0, 2))  # 8
