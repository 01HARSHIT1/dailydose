"""
Basic DSA - Jump Game
You are given an integer array nums where nums[i] is the maximum jump length from index i.
Return True if you can reach the last index, otherwise False.
"""


def can_jump(nums):
    """
    Greedy: track the farthest reachable index.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    far = 0
    for i, jump in enumerate(nums):
        if i > far:
            return False
        far = max(far, i + jump)
        if far >= len(nums) - 1:
            return True
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Jump Game")
    print("=" * 60)

    print(can_jump([2, 3, 1, 1, 4]))  # True
    print(can_jump([3, 2, 1, 0, 4]))  # False
