"""
Basic DSA - Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
"""


def longest_palindrome(s):
    """
    Expand around center for each position (odd and even).
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    if not s:
        return ""

    best_l, best_r = 0, 0

    def expand(l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return l + 1, r - 1

    for i in range(len(s)):
        l1, r1 = expand(i, i)
        if r1 - l1 > best_r - best_l:
            best_l, best_r = l1, r1
        l2, r2 = expand(i, i + 1)
        if r2 - l2 > best_r - best_l:
            best_l, best_r = l2, r2

    return s[best_l : best_r + 1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Palindromic Substring")
    print("=" * 60)

    print(longest_palindrome("babad"))  # bab or aba
    print(longest_palindrome("cbbd"))  # bb
