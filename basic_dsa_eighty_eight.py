"""
Basic DSA - Group Anagrams
Group strings that are anagrams of each other.
"""


def group_anagrams(strs):
    """
    Use sorted string as a key.
    Time Complexity: O(n * k log k) where k is average string length
    Space Complexity: O(n * k)
    """
    groups = {}
    for s in strs:
        key = "".join(sorted(s))
        groups.setdefault(key, []).append(s)
    return list(groups.values())


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Group Anagrams")
    print("=" * 60)

    print(group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    print(group_anagrams([""]))
    print(group_anagrams(["a"]))

