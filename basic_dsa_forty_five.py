"""
Basic DSA - Valid Palindrome (Ignore non-alphanumeric)
Check if a string is a palindrome after converting to lowercase and removing non-alphanumeric characters.
"""


def is_valid_palindrome(s):
    """
    Two-pointer scan from both ends.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(s) - 1

    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1

        if s[left].lower() != s[right].lower():
            return False

        left += 1
        right -= 1

    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Palindrome (Ignore non-alphanumeric)")
    print("=" * 60)

    tests = [
        ("A man, a plan, a canal: Panama", True),
        ("race a car", False),
        ("", True),
        (" ", True),
        ("0P", False),
        ("No 'x' in Nixon", True),
    ]

    for s, expected in tests:
        got = is_valid_palindrome(s)
        print(f"s={s!r} -> {got} (expected {expected})")

