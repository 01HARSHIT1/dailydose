"""
Basic DSA - Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence.
"""


def longest_common_subsequence(text1, text2):
    """
    DP with rolling row.
    Time Complexity: O(n*m)
    Space Complexity: O(min(n, m))
    """
    if len(text2) > len(text1):
        text1, text2 = text2, text1
    # text2 is shorter
    m = len(text2)
    dp = [0] * (m + 1)
    for ch1 in text1:
        prev_diag = 0
        for j, ch2 in enumerate(text2, start=1):
            tmp = dp[j]
            if ch1 == ch2:
                dp[j] = prev_diag + 1
            else:
                dp[j] = max(dp[j], dp[j - 1])
            prev_diag = tmp
    return dp[m]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Common Subsequence")
    print("=" * 60)

    print(longest_common_subsequence("abcde", "ace"))  # 3
    print(longest_common_subsequence("abc", "abc"))  # 3
    print(longest_common_subsequence("abc", "def"))  # 0
