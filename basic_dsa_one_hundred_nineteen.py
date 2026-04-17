"""
Basic DSA - Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).
Supported operators: +, -, *, /
Division truncates toward zero.
"""


def eval_rpn(tokens):
    """
    Stack evaluation.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    stack = []
    for t in tokens:
        if t in {"+", "-", "*", "/"}:
            b = stack.pop()
            a = stack.pop()
            if t == "+":
                stack.append(a + b)
            elif t == "-":
                stack.append(a - b)
            elif t == "*":
                stack.append(a * b)
            else:
                stack.append(int(a / b))  # truncates toward 0 in Python
        else:
            stack.append(int(t))
    return stack[-1] if stack else 0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Evaluate Reverse Polish Notation")
    print("=" * 60)

    print(eval_rpn(["2", "1", "+", "3", "*"]))  # 9
    print(eval_rpn(["4", "13", "5", "/", "+"]))  # 6
    print(eval_rpn(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))  # 22

