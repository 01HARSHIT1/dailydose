"""
Basic DSA - Is Subsequence
Return True if s is a subsequence of t, otherwise False.
"""


def is_subsequence(s, t):
    """
    Two pointers.
    Time Complexity: O(len(t))
    Space Complexity: O(1)
    """
    i = 0
    for ch in t:
        if i < len(s) and s[i] == ch:
            i += 1
    return i == len(s)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Is Subsequence")
    print("=" * 60)

    print(is_subsequence("abc", "ahbgdc"))  # True
    print(is_subsequence("axc", "ahbgdc"))  # False
    print(is_subsequence("", "ahbgdc"))     # True

