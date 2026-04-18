"""
Basic DSA - First Unique Character in a String
Return the index of the first non-repeating character in a string, or -1 if it doesn't exist.
"""


def first_uniq_char(s):
    """
    Count characters then scan.
    Time Complexity: O(n)
    Space Complexity: O(1) for fixed alphabet, otherwise O(m)
    """
    counts = {}
    for ch in s:
        counts[ch] = counts.get(ch, 0) + 1

    for i, ch in enumerate(s):
        if counts[ch] == 1:
            return i
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: First Unique Character in a String")
    print("=" * 60)

    print(first_uniq_char("leetcode"))      # 0
    print(first_uniq_char("loveleetcode"))  # 2
    print(first_uniq_char("aabb"))          # -1

