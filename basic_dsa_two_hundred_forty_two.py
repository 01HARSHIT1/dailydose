"""
Basic DSA - Next Greater Element II
Given a circular integer array nums, return the next greater number for every element.
The next greater number of a number x is the first greater number to its traversing-order
next in the array (wrapping around). If it doesn't exist, return -1.
"""


def next_greater_elements(nums):
    """
    Monotonic decreasing stack of indices over 2 passes.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    n = len(nums)
    res = [-1] * n
    stack = []
    for i in range(2 * n):
        idx = i % n
        while stack and nums[stack[-1]] < nums[idx]:
            res[stack.pop()] = nums[idx]
        if i < n:
            stack.append(idx)
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Next Greater Element II")
    print("=" * 60)

    print(next_greater_elements([1, 2, 1]))  # [2, -1, 2]
    print(next_greater_elements([1, 2, 3, 4, 3]))  # [2, 3, 4, -1, 4]
