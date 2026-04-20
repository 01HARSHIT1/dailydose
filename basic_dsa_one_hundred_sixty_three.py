"""
Basic DSA - Power of Three
Given an integer n, return True if it is a power of three. Otherwise, return False.
"""


def is_power_of_three(n):
    """
    Repeatedly divide by 3 while divisible.
    Time Complexity: O(log_3 n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    while n % 3 == 0:
        n //= 3
    return n == 1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Power of Three")
    print("=" * 60)

    print(is_power_of_three(27))  # True
    print(is_power_of_three(0))  # False
    print(is_power_of_three(9))  # True
    print(is_power_of_three(45))  # False
