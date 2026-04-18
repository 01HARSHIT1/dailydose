"""
Basic DSA - Merge Strings Alternately
Given two strings word1 and word2, merge by adding letters in alternating order.
If one string is longer, append the remaining letters at the end.
"""


def merge_alternately(word1, word2):
    """
    Two pointers.
    Time Complexity: O(n + m)
    Space Complexity: O(n + m) for output
    """
    i = j = 0
    out = []
    while i < len(word1) or j < len(word2):
        if i < len(word1):
            out.append(word1[i])
            i += 1
        if j < len(word2):
            out.append(word2[j])
            j += 1
    return "".join(out)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Strings Alternately")
    print("=" * 60)

    print(merge_alternately("abc", "pqr"))  # "apbqcr"
    print(merge_alternately("ab", "pqrs"))  # "apbqrs"
    print(merge_alternately("abcd", "pq"))  # "apbqcd"

