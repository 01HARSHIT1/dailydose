"""
Basic DSA - Reverse String (In-place)
Given a list of characters, reverse it in-place.
"""


def reverse_string(chars):
    """
    Two-pointer swap.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(chars) - 1
    while left < right:
        chars[left], chars[right] = chars[right], chars[left]
        left += 1
        right -= 1
    return chars


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Reverse String (In-place)")
    print("=" * 60)

    tests = [
        (list("hello"), list("olleh")),
        (list("Hannah"), list("hannaH")),
        ([], []),
        (["a"], ["a"]),
        (["a", " ", "b"], ["b", " ", "a"]),
    ]

    for chars, expected in tests:
        original = chars[:]
        got = reverse_string(chars)
        print(f"chars={original} -> {got} (expected {expected})")

