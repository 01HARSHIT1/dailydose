"""
Basic DSA - Implement Stack using Queues
Implement a LIFO stack using queue operations.
"""

from collections import deque


class MyStack:
    """
    Use a single queue and rotate on push.
    Time Complexity: push O(n), pop/peek O(1)
    Space Complexity: O(n)
    """

    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self):
        return self.q.popleft()

    def top(self):
        return self.q[0]

    def empty(self):
        return not self.q


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Implement Stack using Queues")
    print("=" * 60)

    s = MyStack()
    s.push(1)
    s.push(2)
    print(s.top())   # 2
    print(s.pop())   # 2
    print(s.empty()) # False

