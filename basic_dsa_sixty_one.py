"""
Basic DSA - Queue Using Two Stacks
Implement a FIFO queue using only stack operations (append/pop from end).
"""


class MyQueue:
    """
    Amortized O(1) push/pop/peek.
    Space Complexity: O(n)
    """

    def __init__(self):
        self._in = []
        self._out = []

    def push(self, x):
        self._in.append(x)

    def pop(self):
        self._pour()
        return self._out.pop()

    def peek(self):
        self._pour()
        return self._out[-1]

    def empty(self):
        return not self._in and not self._out

    def _pour(self):
        if not self._out:
            while self._in:
                self._out.append(self._in.pop())


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Queue Using Two Stacks")
    print("=" * 60)

    q = MyQueue()
    q.push(1)
    q.push(2)
    print(f"peek -> {q.peek()} (expected 1)")
    print(f"pop -> {q.pop()} (expected 1)")
    print(f"empty -> {q.empty()} (expected False)")
    print(f"pop -> {q.pop()} (expected 2)")
    print(f"empty -> {q.empty()} (expected True)")
