"""
Basic DSA - Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit.
Return it.
"""


def add_digits(num):
    """
    Digital root:
    - if num == 0 -> 0
    - else -> 1 + (num - 1) % 9
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if num == 0:
        return 0
    return 1 + (num - 1) % 9


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Add Digits")
    print("=" * 60)

    print(add_digits(38))  # 2 (3+8=11, 1+1=2)
    print(add_digits(0))  # 0
