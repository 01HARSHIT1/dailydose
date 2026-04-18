"""
Basic DSA - Valid Palindrome II
Return True if the string can be a palindrome after deleting at most one character.
"""


def valid_palindrome(s):
    """
    Two pointers; when mismatch occurs, try skipping left or right once.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    def is_pal(l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    left, right = 0, len(s) - 1
    while left < right:
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            return is_pal(left + 1, right) or is_pal(left, right - 1)
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Palindrome II")
    print("=" * 60)

    tests = [
        ("aba", True),
        ("abca", True),   # delete 'c'
        ("abc", False),
        ("deeee", True),  # delete 'd'
        ("", True),
    ]

    for s, expected in tests:
        got = valid_palindrome(s)
        print(f"s={s!r} -> {got} (expected {expected})")

