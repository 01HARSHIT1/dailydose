"""
Basic DSA - Find All Duplicates in an Array
Given an integer array nums of length n where all integers are in the range [1, n]
and each integer appears once or twice, return all the integers that appear twice.
"""


def find_duplicates(nums):
    """
    Mark presence by negating nums[abs(x) - 1]; if already negative, it's a duplicate.
    Time Complexity: O(n)
    Space Complexity: O(1) extra (output excluded)
    """
    res = []
    for x in nums:
        idx = abs(x) - 1
        if nums[idx] < 0:
            res.append(abs(x))
        else:
            nums[idx] = -nums[idx]
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find All Duplicates in an Array")
    print("=" * 60)

    print(sorted(find_duplicates([4, 3, 2, 7, 8, 2, 3, 1])))  # [2, 3]
    print(sorted(find_duplicates([1, 1, 2])))  # [1]
