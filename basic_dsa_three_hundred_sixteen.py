"""
Basic DSA - Wiggle Subsequence
Given an integer array nums, return the length of the longest wiggle subsequence.
A wiggle sequence is one where the differences between successive numbers strictly
alternate between positive and negative.
"""


def wiggle_max_length(nums):
    """
    Greedy / DP compression:
    Track best lengths ending with an "up" difference and a "down" difference.

    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return 1

    up = 1
    down = 1
    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            up = down + 1
        elif nums[i] < nums[i - 1]:
            down = up + 1
    return up if up > down else down


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Wiggle Subsequence")
    print("=" * 60)

    print(wiggle_max_length([1, 7, 4, 9, 2, 5]))  # 6
    print(wiggle_max_length([1, 17, 5, 10, 13, 15, 10, 5, 16, 8]))  # 7
    print(wiggle_max_length([1, 2, 3, 4, 5, 6, 7, 8, 9]))  # 2
    print(wiggle_max_length([0, 0, 0]))  # 1
