"""
Basic DSA - Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
"""


def is_valid_parentheses(s):
    """
    Stack + matching map.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    match = {")": "(", "]": "[", "}": "{"}
    stack = []
    for ch in s:
        if ch in match:
            if not stack or stack[-1] != match[ch]:
                return False
            stack.pop()
        else:
            stack.append(ch)
    return not stack


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Parentheses")
    print("=" * 60)

    print(is_valid_parentheses("()"))  # True
    print(is_valid_parentheses("()[]{}"))  # True
    print(is_valid_parentheses("(]"))  # False
