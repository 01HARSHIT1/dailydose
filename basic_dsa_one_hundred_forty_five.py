"""
Basic DSA - Find All Numbers Disappeared in an Array
Given an array nums of length n containing numbers in the range [1, n], where some
numbers appear twice and others appear once, return all the integers in [1, n]
that do not appear in nums.
"""


def find_disappeared_numbers(nums):
    """
    Mark presence by negating the value at index (abs(x) - 1).
    Time Complexity: O(n)
    Space Complexity: O(1) extra (output excluded)
    """
    for x in nums:
        idx = abs(x) - 1
        if nums[idx] > 0:
            nums[idx] = -nums[idx]

    missing = []
    for i, x in enumerate(nums):
        if x > 0:
            missing.append(i + 1)
    return missing


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find All Numbers Disappeared in an Array")
    print("=" * 60)

    print(find_disappeared_numbers([4, 3, 2, 7, 8, 2, 3, 1]))  # [5, 6]
    print(find_disappeared_numbers([1, 1]))  # [2]
