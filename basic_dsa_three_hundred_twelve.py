"""
Basic DSA - House Robber II
You are a professional robber planning to rob houses arranged in a circle.
Adjacent houses cannot both be robbed. Return the maximum amount you can rob.
"""


def rob(nums):
    """
    Reduce circular case to two linear robberies:
    - rob houses [0..n-2]
    - rob houses [1..n-1]
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    if n == 0:
        return 0
    if n == 1:
        return nums[0]

    def rob_linear(arr):
        take = 0
        skip = 0
        for x in arr:
            new_take = skip + x
            skip = max(skip, take)
            take = new_take
        return max(take, skip)

    return max(rob_linear(nums[:-1]), rob_linear(nums[1:]))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: House Robber II")
    print("=" * 60)

    print(rob([2, 3, 2]))  # 3
    print(rob([1, 2, 3, 1]))  # 4
