"""
Basic DSA - Two Sum
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.
Assume exactly one solution, and you may not use the same element twice.
"""


def two_sum(nums, target):
    """
    Hash map from value to index.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    seen = {}
    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return [seen[need], i]
        seen[x] = i
    return [-1, -1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Two Sum")
    print("=" * 60)

    print(two_sum([2, 7, 11, 15], 9))  # [0, 1]
    print(two_sum([3, 2, 4], 6))  # [1, 2]
