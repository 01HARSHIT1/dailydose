"""
Basic DSA - Contains Duplicate
Return True if any value appears at least twice in the array, else False.
"""


def contains_duplicate(nums):
    """
    Use a set to track seen values.
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

    print(contains_duplicate([1, 2, 3, 1]))  # True
    print(contains_duplicate([1, 2, 3, 4]))  # False
