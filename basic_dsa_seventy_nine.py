"""
Basic DSA - Longest Palindromic Substring
Return the longest palindromic substring of s (if several, any valid longest substring is fine).
"""


def longest_palindrome(s):
    """
    Expand around each center (odd and even length palindromes).
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    if not s:
        return ""

    start = end = 0

    def expand(left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1

    for i in range(len(s)):
        l1, r1 = expand(i, i)
        l2, r2 = expand(i, i + 1)
        if r1 - l1 > end - start:
            start, end = l1, r1
        if r2 - l2 > end - start:
            start, end = l2, r2

    return s[start : end + 1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Palindromic Substring")
    print("=" * 60)

    tests = [
        ("babad", 3),
        ("cbbd", 2),
        ("a", 1),
        ("ac", 1),
        ("", 0),
    ]

    for s, expected_len in tests:
        got = longest_palindrome(s)
        is_pal = got == got[::-1]
        print(f"s={s!r} -> {got!r} len={len(got)} (expected len {expected_len}, palindrome={is_pal})")
