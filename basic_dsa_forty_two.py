"""
Basic DSA - Valid Anagram
Check if two strings are anagrams of each other.
"""


def is_anagram(s, t):
    """
    Count characters and compare.
    Time Complexity: O(n)
    Space Complexity: O(1) (bounded by charset)
    """
    if len(s) != len(t):
        return False

    counts = {}
    for ch in s:
        counts[ch] = counts.get(ch, 0) + 1

    for ch in t:
        if ch not in counts:
            return False
        counts[ch] -= 1
        if counts[ch] == 0:
            del counts[ch]

    return not counts


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Anagram")
    print("=" * 60)

    tests = [
        ("anagram", "nagaram", True),
        ("rat", "car", False),
        ("aacc", "ccac", False),
        ("", "", True),
        ("aa", "a", False),
        ("a", "A", False),
    ]

    for s, t, expected in tests:
        got = is_anagram(s, t)
        print(f"s={s!r}, t={t!r} -> {got} (expected {expected})")

