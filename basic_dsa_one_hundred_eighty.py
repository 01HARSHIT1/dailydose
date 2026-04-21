"""
Basic DSA - Implement Stack using Queues
Implement a last in first out (LIFO) stack using only queue operations.
"""

from collections import deque


class MyStack:
    """
    Use a single queue and rotate after each push.
    Time Complexity: push O(n), pop/top O(1)
    Space Complexity: O(n)
    """

    def __init__(self):
        self._q = deque()

    def push(self, x):
        self._q.append(x)
        for _ in range(len(self._q) - 1):
            self._q.append(self._q.popleft())

    def pop(self):
        return self._q.popleft()

    def top(self):
        return self._q[0]

    def empty(self):
        return not self._q


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Implement Stack using Queues")
    print("=" * 60)

    st = MyStack()
    st.push(1)
    st.push(2)
    print(st.top())  # 2
    print(st.pop())  # 2
    print(st.empty())  # False
