"""
Basic DSA - Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t,
with a one-to-one mapping (no two chars map to same char).
"""


def is_isomorphic(s, t):
    """
    Maintain forward and backward maps to enforce one-to-one mapping.
    Time Complexity: O(n)
    Space Complexity: O(k) where k is number of distinct chars
    """
    if len(s) != len(t):
        return False

    s_to_t = {}
    t_to_s = {}
    for a, b in zip(s, t):
        if a in s_to_t and s_to_t[a] != b:
            return False
        if b in t_to_s and t_to_s[b] != a:
            return False
        s_to_t[a] = b
        t_to_s[b] = a
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Isomorphic Strings")
    print("=" * 60)

    print(is_isomorphic("egg", "add"))  # True
    print(is_isomorphic("foo", "bar"))  # False
    print(is_isomorphic("paper", "title"))  # True
