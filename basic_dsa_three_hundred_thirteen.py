"""
Basic DSA - Decode Ways
A message containing letters from A-Z can be encoded as numbers using:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".
Given a string s containing only digits, return the number of ways to decode it.
"""


def num_decodings(s):
    """
    DP with rolling variables:
    dp[i] depends on dp[i-1] and dp[i-2] based on 1-digit and 2-digit validity.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not s or s[0] == "0":
        return 0

    prev2 = 1  # dp[i-2]
    prev1 = 1  # dp[i-1]

    for i in range(1, len(s)):
        cur = 0
        if s[i] != "0":
            cur += prev1
        two = int(s[i - 1 : i + 1])
        if 10 <= two <= 26:
            cur += prev2
        prev2, prev1 = prev1, cur
        if prev1 == 0:
            # early stop if no ways so far
            return 0

    return prev1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Decode Ways")
    print("=" * 60)

    print(num_decodings("12"))  # 2
    print(num_decodings("226"))  # 3
    print(num_decodings("06"))  # 0
