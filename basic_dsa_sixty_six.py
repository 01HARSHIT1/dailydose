"""
Basic DSA - Longest Substring Without Repeating Characters
Return the length of the longest substring that contains no repeated characters.
"""


def length_of_longest_substring(s):
    """
    Sliding window with last-seen index for each character.
    Time Complexity: O(n)
    Space Complexity: O(min(n, alphabet size))
    """
    last = {}
    start = 0
    best = 0

    for end, ch in enumerate(s):
        if ch in last and last[ch] >= start:
            start = last[ch] + 1
        last[ch] = end
        best = max(best, end - start + 1)

    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Substring Without Repeating Characters")
    print("=" * 60)

    tests = [
        ("abcabcbb", 3),
        ("bbbbb", 1),
        ("pwwkew", 3),
        ("", 0),
        ("dvdf", 3),
    ]

    for s, expected in tests:
        got = length_of_longest_substring(s)
        print(f"s={s!r} -> {got} (expected {expected})")
