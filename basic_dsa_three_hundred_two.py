"""
Basic DSA - Range Sum Query - Immutable
Given an integer array nums, handle multiple queries of the following type:
Return the sum of the elements of nums between indices left and right inclusive.
"""


class NumArray:
    """
    Prefix sums.
    Build: O(n)
    Query: O(1)
    Space: O(n)
    """

    def __init__(self, nums):
        self.pref = [0]
        running = 0
        for x in nums:
            running += x
            self.pref.append(running)

    def sum_range(self, left, right):
        return self.pref[right + 1] - self.pref[left]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Range Sum Query - Immutable")
    print("=" * 60)

    num_array = NumArray([-2, 0, 3, -5, 2, -1])
    print(num_array.sum_range(0, 2))  # 1
    print(num_array.sum_range(2, 5))  # -1
    print(num_array.sum_range(0, 5))  # -3
