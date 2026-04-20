"""
Basic DSA - Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb 1 or 2 steps. Return the number of distinct ways to climb.
"""


def climb_stairs(n):
    """
    Fibonacci DP with O(1) space.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 2:
        return n
    a, b = 1, 2
    for _ in range(3, n + 1):
        a, b = b, a + b
    return b


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Climbing Stairs")
    print("=" * 60)

    print(climb_stairs(2))  # 2
    print(climb_stairs(3))  # 3
    print(climb_stairs(5))  # 8
