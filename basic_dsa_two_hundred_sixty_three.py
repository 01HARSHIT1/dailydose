"""
Basic DSA - Basic Calculator II
Given a string s representing a valid expression, evaluate it and return the result.
The expression contains non-negative integers and operators +, -, *, / with spaces.
Division truncates toward zero.
"""


def calculate(s):
    """
    One pass using a stack for * and / precedence.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    stack = []
    num = 0
    op = "+"
    for i, ch in enumerate(s):
        if ch.isdigit():
            num = num * 10 + (ord(ch) - ord("0"))
        if (not ch.isdigit() and ch != " ") or i == len(s) - 1:
            if op == "+":
                stack.append(num)
            elif op == "-":
                stack.append(-num)
            elif op == "*":
                stack.append(stack.pop() * num)
            else:  # "/"
                stack.append(int(stack.pop() / num))
            op = ch
            num = 0
    return sum(stack)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Basic Calculator II")
    print("=" * 60)

    print(calculate("3+2*2"))  # 7
    print(calculate(" 3/2 "))  # 1
    print(calculate(" 3+5 / 2 "))  # 5
