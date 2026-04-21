"""
Basic DSA - Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
"""


def longest_common_prefix(strs):
    """
    Horizontal scanning: keep shrinking the prefix until all strings match.
    Time Complexity: O(total characters compared)
    Space Complexity: O(1) extra
    """
    if not strs:
        return ""
    prefix = strs[0]
    for s in strs[1:]:
        while not s.startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    return prefix


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Common Prefix")
    print("=" * 60)

    print(longest_common_prefix(["flower", "flow", "flight"]))  # fl
    print(longest_common_prefix(["dog", "racecar", "car"]))  # ""
