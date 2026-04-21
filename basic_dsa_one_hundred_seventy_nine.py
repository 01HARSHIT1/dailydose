"""
Basic DSA - Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks.
"""


class MyQueue:
    """
    Use two stacks:
    - in_stack for push operations
    - out_stack for pop/peek; refill from in_stack when needed
    Amortized Time Complexity: O(1) per op
    Space Complexity: O(n)
    """

    def __init__(self):
        self._in = []
        self._out = []

    def push(self, x):
        self._in.append(x)

    def _pour(self):
        if not self._out:
            while self._in:
                self._out.append(self._in.pop())

    def pop(self):
        self._pour()
        return self._out.pop()

    def peek(self):
        self._pour()
        return self._out[-1]

    def empty(self):
        return not self._in and not self._out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Implement Queue using Stacks")
    print("=" * 60)

    q = MyQueue()
    q.push(1)
    q.push(2)
    print(q.peek())  # 1
    print(q.pop())  # 1
    print(q.empty())  # False
