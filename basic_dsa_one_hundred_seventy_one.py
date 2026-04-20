"""
Basic DSA - Word Pattern
Given a pattern and a string s, return True if s follows the same pattern.
Each pattern character maps to exactly one word and vice versa.
"""


def word_pattern(pattern, s):
    """
    Two-way mapping between chars and words.
    Time Complexity: O(n)
    Space Complexity: O(k)
    """
    words = s.split()
    if len(pattern) != len(words):
        return False

    p_to_w = {}
    w_to_p = {}
    for ch, w in zip(pattern, words):
        if ch in p_to_w and p_to_w[ch] != w:
            return False
        if w in w_to_p and w_to_p[w] != ch:
            return False
        p_to_w[ch] = w
        w_to_p[w] = ch
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Word Pattern")
    print("=" * 60)

    print(word_pattern("abba", "dog cat cat dog"))  # True
    print(word_pattern("abba", "dog cat cat fish"))  # False
    print(word_pattern("aaaa", "dog cat cat dog"))  # False
