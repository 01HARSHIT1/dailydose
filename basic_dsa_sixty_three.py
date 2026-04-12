"""
Basic DSA - Product of Array Except Self
Return an array answer where answer[i] is the product of all elements of nums except nums[i],
without using division and in O(n) time.
"""


def product_except_self(nums):
    """
    Prefix products left-to-right, then multiply by suffix products right-to-left.
    Time Complexity: O(n)
    Space Complexity: O(1) extra excluding the output array
    """
    n = len(nums)
    answer = [1] * n

    prefix = 1
    for i in range(n):
        answer[i] = prefix
        prefix *= nums[i]

    suffix = 1
    for i in range(n - 1, -1, -1):
        answer[i] *= suffix
        suffix *= nums[i]

    return answer


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Product of Array Except Self")
    print("=" * 60)

    tests = [
        ([1, 2, 3, 4], [24, 12, 8, 6]),
        ([-1, 1, 0, -3, 3], [0, 0, 9, 0, 0]),
        ([2, 3], [3, 2]),
    ]

    for nums, expected in tests:
        got = product_except_self(nums)
        print(f"nums={nums} -> {got} (expected {expected})")
