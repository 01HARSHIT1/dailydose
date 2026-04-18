"""
Basic DSA - Minimum Stack (O(1) getMin)
Design a stack that supports push, pop, top, and getMin in constant time.
"""


class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        val = self.stack.pop()
        if val == self.min_stack[-1]:
            self.min_stack.pop()
        return val

    def top(self):
        return self.stack[-1]

    def get_min(self):
        return self.min_stack[-1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Stack (O(1) getMin)")
    print("=" * 60)

    s = MinStack()
    s.push(-2)
    s.push(0)
    s.push(-3)
    print(s.get_min())  # -3
    s.pop()
    print(s.top())      # 0
    print(s.get_min())  # -2

