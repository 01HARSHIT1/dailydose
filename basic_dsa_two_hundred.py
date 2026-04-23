"""
Basic DSA - Group Anagrams
Given an array of strings, group the anagrams together.
Return the groups in any order.
"""

from collections import defaultdict


def group_anagrams(strs):
    """
    Key by sorted characters.
    Time Complexity: O(n * k log k) where k is average word length
    Space Complexity: O(n * k)
    """
    groups = defaultdict(list)
    for s in strs:
        groups["".join(sorted(s))].append(s)
    return list(groups.values())


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Group Anagrams")
    print("=" * 60)

    res = group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    # print sorted groups for stable demo output
    print(sorted([sorted(g) for g in res]))
