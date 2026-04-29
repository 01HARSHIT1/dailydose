"""
Basic DSA - Edit Distance
Given two strings word1 and word2, return the minimum number of operations required
to convert word1 to word2.

Allowed operations:
- Insert a character
- Delete a character
- Replace a character
"""


def min_distance(word1, word2):
    """
    Dynamic Programming with rolling row optimization.
    Time Complexity: O(n*m)
    Space Complexity: O(min(n, m))
    """
    if len(word2) > len(word1):
        word1, word2 = word2, word1

    m = len(word2)
    dp = list(range(m + 1))

    for i, c1 in enumerate(word1, start=1):
        prev_diag = dp[0]
        dp[0] = i
        for j, c2 in enumerate(word2, start=1):
            temp = dp[j]
            if c1 == c2:
                dp[j] = prev_diag
            else:
                dp[j] = 1 + min(prev_diag, dp[j], dp[j - 1])
            prev_diag = temp
    return dp[m]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Edit Distance")
    print("=" * 60)

    print(min_distance("horse", "ros"))  # 3
    print(min_distance("intention", "execution"))  # 5
