"""
Basic DSA - Backspace String Compare
Given two strings s and t, return True if they are equal when typed into empty text
editors. '#' means a backspace character.
"""


def _next_valid_index(s, i):
    skip = 0
    while i >= 0:
        if s[i] == "#":
            skip += 1
            i -= 1
        elif skip:
            skip -= 1
            i -= 1
        else:
            return i
    return -1


def backspace_compare(s, t):
    """
    Two pointers from the end, skipping backspaced chars.
    Time Complexity: O(n + m)
    Space Complexity: O(1)
    """
    i, j = len(s) - 1, len(t) - 1
    while True:
        i = _next_valid_index(s, i)
        j = _next_valid_index(t, j)
        if i < 0 or j < 0:
            return i == j
        if s[i] != t[j]:
            return False
        i -= 1
        j -= 1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Backspace String Compare")
    print("=" * 60)

    print(backspace_compare("ab#c", "ad#c"))  # True
    print(backspace_compare("ab##", "c#d#"))  # True
    print(backspace_compare("a#c", "b"))  # False
