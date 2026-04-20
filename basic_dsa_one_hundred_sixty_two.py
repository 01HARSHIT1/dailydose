"""
Basic DSA - Power of Two
Given an integer n, return True if it is a power of two. Otherwise, return False.
"""


def is_power_of_two(n):
    """
    A power of two has exactly one set bit in binary representation.
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return n > 0 and (n & (n - 1)) == 0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Power of Two")
    print("=" * 60)

    print(is_power_of_two(1))  # True
    print(is_power_of_two(16))  # True
    print(is_power_of_two(3))  # False
    print(is_power_of_two(0))  # False
