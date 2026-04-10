"""
Basic DSA - Valid Parentheses
Given a string containing only '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
"""


def is_valid(s):
    """
    Stack with closing-to-opening map.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    stack = []
    pairs = {")": "(", "}": "{", "]": "["}
    for ch in s:
        if ch in pairs:
            if not stack or stack[-1] != pairs[ch]:
                return False
            stack.pop()
        else:
            stack.append(ch)
    return len(stack) == 0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Parentheses")
    print("=" * 60)

    tests = [
        ("()", True),
        ("()[]{}", True),
        ("(]", False),
        ("([)]", False),
        ("{[]}", True),
        ("", True),
    ]

    for s, expected in tests:
        got = is_valid(s)
        print(f"s={s!r} -> {got} (expected {expected})")
