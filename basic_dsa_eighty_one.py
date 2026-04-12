"""
Basic DSA - Decode Ways
A message containing letters A–Z can be encoded to numbers 1–26.
Given a string of digits, return how many ways it can be decoded.
"""


def num_decodings(s):
    """
    Dynamic programming: at each index, extend valid one-digit or two-digit codes.
    Time Complexity: O(n)
    Space Complexity: O(n) (can be O(1) with two variables)
    """
    if not s or s[0] == "0":
        return 0

    n = len(s)
    dp = [0] * n
    dp[0] = 1

    for i in range(1, n):
        one = int(s[i])
        if 1 <= one <= 9:
            dp[i] += dp[i - 1]

        two = int(s[i - 1 : i + 1])
        if 10 <= two <= 26:
            dp[i] += dp[i - 2] if i >= 2 else 1

    return dp[-1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Decode Ways")
    print("=" * 60)

    tests = [
        ("12", 2),
        ("226", 3),
        ("06", 0),
        ("10", 1),
        ("27", 1),
    ]

    for s, expected in tests:
        got = num_decodings(s)
        print(f"s={s!r} -> {got} (expected {expected})")
