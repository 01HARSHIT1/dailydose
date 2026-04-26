"""
Basic DSA - Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
"""


def length_of_longest_substring(s):
    """
    Sliding window with last seen positions.
    Time Complexity: O(n)
    Space Complexity: O(min(n, alphabet))
    """
    last = {}
    left = 0
    best = 0
    for right, ch in enumerate(s):
        if ch in last and last[ch] >= left:
            left = last[ch] + 1
        last[ch] = right
        best = max(best, right - left + 1)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Substring Without Repeating Characters")
    print("=" * 60)

    print(length_of_longest_substring("abcabcbb"))  # 3
    print(length_of_longest_substring("bbbbb"))  # 1
    print(length_of_longest_substring("pwwkew"))  # 3
