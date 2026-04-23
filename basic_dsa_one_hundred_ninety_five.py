"""
Basic DSA - Valid Perfect Square
Given a positive integer num, return True if num is a perfect square, else False.
Do not use any built-in library function like sqrt.
"""


def is_perfect_square(num):
    """
    Binary search on [1, num].
    Time Complexity: O(log num)
    Space Complexity: O(1)
    """
    if num < 1:
        return False
    lo, hi = 1, num
    while lo <= hi:
        mid = (lo + hi) // 2
        sq = mid * mid
        if sq == num:
            return True
        if sq < num:
            lo = mid + 1
        else:
            hi = mid - 1
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Perfect Square")
    print("=" * 60)

    print(is_perfect_square(16))  # True
    print(is_perfect_square(14))  # False
