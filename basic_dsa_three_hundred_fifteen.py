"""
Basic DSA - Count of Smaller Numbers After Self
Given an integer array nums, return an array counts where counts[i] is the number of
smaller elements to the right of nums[i].
"""


def count_smaller(nums):
    """
    Fenwick Tree over coordinate-compressed values.
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    """
    if not nums:
        return []

    vals = sorted(set(nums))
    idx = {v: i + 1 for i, v in enumerate(vals)}  # 1-based for BIT
    size = len(vals)

    bit = [0] * (size + 1)

    def add(i, delta):
        while i <= size:
            bit[i] += delta
            i += i & -i

    def sum_(i):
        s = 0
        while i > 0:
            s += bit[i]
            i -= i & -i
        return s

    res = [0] * len(nums)
    for i in range(len(nums) - 1, -1, -1):
        r = idx[nums[i]]
        res[i] = sum_(r - 1)
        add(r, 1)
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Count of Smaller Numbers After Self")
    print("=" * 60)

    print(count_smaller([5, 2, 6, 1]))  # [2, 1, 1, 0]
    print(count_smaller([-1, -1]))  # [0, 0]
