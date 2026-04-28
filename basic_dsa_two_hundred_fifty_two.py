"""
Basic DSA - Jump Game II
You are given an integer array nums where nums[i] is the maximum jump length from index i.
Return the minimum number of jumps to reach the last index.
Assume you can always reach the last index.
"""


def jump(nums):
    """
    Greedy BFS-level approach:
    Track current range [0..end] reachable with 'steps' jumps, and the farthest reach
    within that range. When i hits end, we must take another jump.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if len(nums) <= 1:
        return 0

    steps = 0
    end = 0
    far = 0
    for i in range(len(nums) - 1):
        far = max(far, i + nums[i])
        if i == end:
            steps += 1
            end = far
    return steps


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Jump Game II")
    print("=" * 60)

    print(jump([2, 3, 1, 1, 4]))  # 2
    print(jump([2, 3, 0, 1, 4]))  # 2
