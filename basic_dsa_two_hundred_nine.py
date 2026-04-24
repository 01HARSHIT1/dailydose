"""
Basic DSA - Find All Anagrams in a String
Given two strings s and p, return a list of all start indices of p's anagrams in s.
The answer can be in any order.
"""


def find_anagrams(s, p):
    """
    Sliding window character counts over lowercase English letters.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if len(p) > len(s):
        return []

    def idx(ch):
        return ord(ch) - ord("a")

    need = [0] * 26
    win = [0] * 26
    for ch in p:
        need[idx(ch)] += 1

    res = []
    m = len(p)
    for i, ch in enumerate(s):
        win[idx(ch)] += 1
        if i >= m:
            win[idx(s[i - m])] -= 1
        if i >= m - 1 and win == need:
            res.append(i - m + 1)
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find All Anagrams in a String")
    print("=" * 60)

    print(find_anagrams("cbaebabacd", "abc"))  # [0, 6]
    print(find_anagrams("abab", "ab"))  # [0, 1, 2]
