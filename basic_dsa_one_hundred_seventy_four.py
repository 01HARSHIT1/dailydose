"""
Basic DSA - Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.
"""


class MinStack:
    """
    Store pairs (value, current_min).
    Time Complexity: O(1) per operation
    Space Complexity: O(n)
    """

    def __init__(self):
        self._stack = []

    def push(self, val):
        cur_min = val if not self._stack else min(val, self._stack[-1][1])
        self._stack.append((val, cur_min))

    def pop(self):
        self._stack.pop()

    def top(self):
        return self._stack[-1][0]

    def get_min(self):
        return self._stack[-1][1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Min Stack")
    print("=" * 60)

    st = MinStack()
    st.push(-2)
    st.push(0)
    st.push(-3)
    print(st.get_min())  # -3
    st.pop()
    print(st.top())  # 0
    print(st.get_min())  # -2
