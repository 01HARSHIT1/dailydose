"""
Basic DSA - Valid Palindrome II
Given a string s, return True if the string can be a palindrome after deleting at
most one character.
"""


def valid_palindrome_ii(s):
    """
    Two pointers; on first mismatch, try skipping either side once.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """

    def is_pal(i, j):
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    i, j = 0, len(s) - 1
    while i < j:
        if s[i] == s[j]:
            i += 1
            j -= 1
        else:
            return is_pal(i + 1, j) or is_pal(i, j - 1)
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Palindrome II")
    print("=" * 60)

    print(valid_palindrome_ii("aba"))  # True
    print(valid_palindrome_ii("abca"))  # True (delete 'c')
    print(valid_palindrome_ii("abc"))  # False
