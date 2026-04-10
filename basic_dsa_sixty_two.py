"""
Basic DSA - Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in O(1).
"""


class MinStack:
    """
    Keep a parallel stack of minimums seen so far.
    Time Complexity: O(1) per operation amortized
    Space Complexity: O(n)
    """

    def __init__(self):
        self._stack = []
        self._mins = []

    def push(self, val):
        self._stack.append(val)
        if not self._mins or val <= self._mins[-1]:
            self._mins.append(val)

    def pop(self):
        val = self._stack.pop()
        if val == self._mins[-1]:
            self._mins.pop()
        return val

    def top(self):
        return self._stack[-1]

    def getMin(self):
        return self._mins[-1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Min Stack")
    print("=" * 60)

    ms = MinStack()
    ms.push(-2)
    ms.push(0)
    ms.push(-3)
    print(f"getMin -> {ms.getMin()} (expected -3)")
    ms.pop()
    print(f"top -> {ms.top()} (expected 0)")
    print(f"getMin -> {ms.getMin()} (expected -2)")
