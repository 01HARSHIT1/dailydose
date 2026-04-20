"""
Basic DSA - House Robber
Given an integer array nums representing the amount of money at each house,
return the maximum amount you can rob tonight without robbing adjacent houses.
"""


def rob(nums):
    """
    DP with two variables:
    - take: best if we take current house
    - skip: best if we skip current house
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    take = 0
    skip = 0
    for x in nums:
        new_take = skip + x
        skip = max(skip, take)
        take = new_take
    return max(take, skip)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: House Robber")
    print("=" * 60)

    print(rob([1, 2, 3, 1]))  # 4
    print(rob([2, 7, 9, 3, 1]))  # 12
