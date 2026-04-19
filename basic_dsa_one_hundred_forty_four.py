"""
Basic DSA - Third Maximum Number
Return the third distinct maximum in nums; if fewer than three distinct values exist,
return the maximum.
"""


def third_max(nums):
    """
    Track top three distinct values in one pass.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    first = second = third = None
    for x in nums:
        if x == first or x == second or x == third:
            continue
        if first is None or x > first:
            third, second, first = second, first, x
        elif second is None or x > second:
            third, second = second, x
        elif third is None or x > third:
            third = x
    return first if third is None else third


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Third Maximum Number")
    print("=" * 60)

    print(third_max([3, 2, 1]))  # 1
    print(third_max([1, 2]))  # 2
    print(third_max([2, 2, 3, 1]))  # 1
