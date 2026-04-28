"""
Basic DSA - Basic Calculator
Implement a basic calculator to evaluate a simple expression string s.
The expression may contain parentheses, +, -, non-negative integers, and spaces.
"""


def calculate(s):
    """
    Use a stack for previous result and sign when entering parentheses.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    res = 0
    sign = 1
    num = 0
    stack = []

    for ch in s:
        if ch.isdigit():
            num = num * 10 + (ord(ch) - ord("0"))
        elif ch in "+-":
            res += sign * num
            num = 0
            sign = 1 if ch == "+" else -1
        elif ch == "(":
            stack.append(res)
            stack.append(sign)
            res = 0
            sign = 1
        elif ch == ")":
            res += sign * num
            num = 0
            res *= stack.pop()  # sign
            res += stack.pop()  # previous res
        else:
            # space or other ignored char
            pass

    res += sign * num
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Basic Calculator")
    print("=" * 60)

    print(calculate("1 + 1"))  # 2
    print(calculate(" 2-1 + 2 "))  # 3
    print(calculate("(1+(4+5+2)-3)+(6+8)"))  # 23
