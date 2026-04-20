"""
Basic DSA - Sqrt(x)
Given a non-negative integer x, compute and return the integer square root of x.
The return value should be the floor of the true square root.
"""


def my_sqrt(x):
    """
    Binary search on [0, x].
    Time Complexity: O(log x)
    Space Complexity: O(1)
    """
    if x < 2:
        return x
    lo, hi = 1, x // 2
    ans = 1
    while lo <= hi:
        mid = (lo + hi) // 2
        sq = mid * mid
        if sq == x:
            return mid
        if sq < x:
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return ans


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Sqrt(x)")
    print("=" * 60)

    print(my_sqrt(4))  # 2
    print(my_sqrt(8))  # 2
