"""
Basic DSA - Sliding Window Maximum
Given an array nums and a sliding window size k, return the maximum value in each
window as it moves from left to right.
"""

from collections import deque


def max_sliding_window(nums, k):
    """
    Monotonic deque of indices (values decreasing).
    Time Complexity: O(n)
    Space Complexity: O(k)
    """
    if not nums or k <= 0:
        return []
    dq = deque()
    out = []
    for i, x in enumerate(nums):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and nums[dq[-1]] <= x:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            out.append(nums[dq[0]])
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Sliding Window Maximum")
    print("=" * 60)

    print(max_sliding_window([1, 3, -1, -3, 5, 3, 6, 7], 3))  # [3, 3, 5, 5, 6, 7]
    print(max_sliding_window([1], 1))  # [1]
