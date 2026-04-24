"""
Basic DSA - Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is the
product of all the elements of nums except nums[i].
You must write an algorithm that runs in O(n) time and without using division.
"""


def product_except_self(nums):
    """
    Prefix products then multiply by suffix products in a second pass.
    Time Complexity: O(n)
    Space Complexity: O(1) extra (output excluded)
    """
    n = len(nums)
    out = [1] * n

    pref = 1
    for i in range(n):
        out[i] = pref
        pref *= nums[i]

    suff = 1
    for i in range(n - 1, -1, -1):
        out[i] *= suff
        suff *= nums[i]

    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Product of Array Except Self")
    print("=" * 60)

    print(product_except_self([1, 2, 3, 4]))  # [24, 12, 8, 6]
    print(product_except_self([-1, 1, 0, -3, 3]))  # [0, 0, 9, 0, 0]
