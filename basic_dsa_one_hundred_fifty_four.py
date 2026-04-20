"""
Basic DSA - Find the Difference
Given two strings s and t where t is s with one extra character added (and shuffled),
return the extra character.
"""


def find_the_difference(s, t):
    """
    XOR all character code points; pairs cancel, leaving the extra char.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    x = 0
    for ch in s:
        x ^= ord(ch)
    for ch in t:
        x ^= ord(ch)
    return chr(x)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find the Difference")
    print("=" * 60)

    print(find_the_difference("abcd", "abcde"))  # e
    print(find_the_difference("", "y"))  # y
