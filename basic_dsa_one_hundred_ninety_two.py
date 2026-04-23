"""
Basic DSA - Rotate String
Given two strings s and goal, return True if and only if s can become goal after
some number of shifts on s.
A shift consists of moving the leftmost character to the rightmost position.
"""


def rotate_string(s, goal):
    """
    s is a rotation of goal iff len equal and goal is substring of s+s.
    Time Complexity: O(n) average (substring search)
    Space Complexity: O(n) for s+s
    """
    return len(s) == len(goal) and goal in (s + s)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotate String")
    print("=" * 60)

    print(rotate_string("abcde", "cdeab"))  # True
    print(rotate_string("abcde", "abced"))  # False
