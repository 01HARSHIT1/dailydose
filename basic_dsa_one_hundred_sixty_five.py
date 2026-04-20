"""
Basic DSA - Happy Number
Write an algorithm to determine if a number n is happy.
A happy number eventually reaches 1 when replaced by the sum of squares of its digits.
If it loops (never reaches 1), it is not happy.
"""


def _next_value(n):
    s = 0
    while n:
        n, d = divmod(n, 10)
        s += d * d
    return s


def is_happy(n):
    """
    Floyd cycle detection on the digit-square-sum sequence.
    Time Complexity: O(steps) (small in practice)
    Space Complexity: O(1)
    """
    slow = n
    fast = _next_value(n)
    while fast != 1 and slow != fast:
        slow = _next_value(slow)
        fast = _next_value(_next_value(fast))
    return fast == 1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Happy Number")
    print("=" * 60)

    print(is_happy(19))  # True
    print(is_happy(2))  # False
