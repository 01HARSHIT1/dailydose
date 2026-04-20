"""
Basic DSA - Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the
only number in the range that is missing from the array.
"""


def missing_number(nums):
    """
    XOR indices and values: pairs cancel, leaving the missing number.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    x = len(nums)
    for i, v in enumerate(nums):
        x ^= i ^ v
    return x


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Missing Number")
    print("=" * 60)

    print(missing_number([3, 0, 1]))  # 2
    print(missing_number([0, 1]))  # 2
    print(missing_number([9, 6, 4, 2, 3, 5, 7, 0, 1]))  # 8
