"""
Basic DSA - Plus One
Given a non-empty array of decimal digits representing a non-negative integer,
increment the integer by one and return the resulting digits.
"""


def plus_one(digits):
    """
    Add from the end with carry.
    Time Complexity: O(n)
    Space Complexity: O(1) extra (may allocate if we need a new leading digit)
    """
    i = len(digits) - 1
    while i >= 0 and digits[i] == 9:
        digits[i] = 0
        i -= 1
    if i >= 0:
        digits[i] += 1
        return digits
    return [1] + digits


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Plus One")
    print("=" * 60)

    print(plus_one([1, 2, 3]))  # [1, 2, 4]
    print(plus_one([4, 3, 2, 1]))  # [4, 3, 2, 2]
    print(plus_one([9]))  # [1, 0]
