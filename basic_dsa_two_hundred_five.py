"""
Basic DSA - Summary Ranges
Given a sorted unique integer array nums, return the smallest sorted list of ranges
that cover all the numbers exactly.
"""


def summary_ranges(nums):
    """
    Sweep and close ranges when breaks appear.
    Time Complexity: O(n)
    Space Complexity: O(1) extra (output excluded)
    """
    res = []
    if not nums:
        return res

    start = prev = nums[0]
    for x in nums[1:]:
        if x == prev + 1:
            prev = x
            continue
        res.append(str(start) if start == prev else f"{start}->{prev}")
        start = prev = x
    res.append(str(start) if start == prev else f"{start}->{prev}")
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Summary Ranges")
    print("=" * 60)

    print(summary_ranges([0, 1, 2, 4, 5, 7]))  # ['0->2', '4->5', '7']
    print(summary_ranges([0, 2, 3, 4, 6, 8, 9]))  # ['0', '2->4', '6', '8->9']
