"""
Basic DSA - Contains Duplicate
Return True if any value appears at least twice in the array, otherwise False.
"""


def contains_duplicate(nums):
    """
    Use a set to track seen elements.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    seen = set()
    for x in nums:
        if x in seen:
            return True
        seen.add(x)
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Contains Duplicate")
    print("=" * 60)

    tests = [
        ([1, 2, 3, 1], True),
        ([1, 2, 3, 4], False),
        ([1, 1, 1, 3, 3, 4, 3, 2, 4, 2], True),
        ([], False),
        ([0], False),
    ]

    for nums, expected in tests:
        got = contains_duplicate(nums)
        print(f"nums={nums} -> {got} (expected {expected})")

