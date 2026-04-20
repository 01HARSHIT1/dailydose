"""
Basic DSA - Valid Palindrome
Given a string s, return True if it is a palindrome, considering only alphanumeric
characters and ignoring cases.
"""


def is_palindrome(s):
    """
    Two pointers; skip non-alphanumeric characters.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    i, j = 0, len(s) - 1
    while i < j:
        while i < j and not s[i].isalnum():
            i += 1
        while i < j and not s[j].isalnum():
            j -= 1
        if s[i].lower() != s[j].lower():
            return False
        i += 1
        j -= 1
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Palindrome")
    print("=" * 60)

    print(is_palindrome("A man, a plan, a canal: Panama"))  # True
    print(is_palindrome("race a car"))  # False
