"""
Basic DSA - Valid Anagram
Given two strings s and t, return True if t is an anagram of s, and False otherwise.
"""

from collections import Counter


def is_anagram(s, t):
    """
    Compare character counts.
    Time Complexity: O(n + m)
    Space Complexity: O(k) where k is alphabet size used in strings
    """
    return Counter(s) == Counter(t)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Anagram")
    print("=" * 60)

    print(is_anagram("anagram", "nagaram"))  # True
    print(is_anagram("rat", "car"))  # False
