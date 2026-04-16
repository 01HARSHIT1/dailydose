"""
Basic DSA - Find All Duplicates in an Array
Given an integer array nums of length n where each integer is in the range [1, n],
return all the integers that appear twice.
"""


def find_duplicates(nums):
    """
    Mark visited indices by negating nums[abs(x)-1].
    Time Complexity: O(n)
    Space Complexity: O(1) extra (mutates nums)
    """
    dup = []
    for x in nums:
        i = abs(x) - 1
        if nums[i] < 0:
            dup.append(abs(x))
        else:
            nums[i] = -nums[i]
    return dup


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find All Duplicates in an Array")
    print("=" * 60)

    print(find_duplicates([4, 3, 2, 7, 8, 2, 3, 1]))  # [2, 3]
    print(find_duplicates([1, 1, 2]))  # [1]
    print(find_duplicates([1]))  # []

