"""
Basic DSA - Longest Repeating Character Replacement
Given a string s and an integer k, return the length of the longest substring containing the same letter
you can get after performing at most k character replacements.
"""


def character_replacement(s, k):
    """
    Sliding window with frequency map.
    Keep window valid when (window_size - max_freq_in_window) <= k.
    Time Complexity: O(n)
    Space Complexity: O(1) for fixed alphabet (uppercase letters), otherwise O(m)
    """
    counts = {}
    left = 0
    max_freq = 0
    best = 0

    for right, ch in enumerate(s):
        counts[ch] = counts.get(ch, 0) + 1
        max_freq = max(max_freq, counts[ch])

        while (right - left + 1) - max_freq > k:
            counts[s[left]] -= 1
            left += 1

        best = max(best, right - left + 1)

    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Repeating Character Replacement")
    print("=" * 60)

    print(character_replacement("ABAB", 2))  # 4
    print(character_replacement("AABABBA", 1))  # 4
    print(character_replacement("", 5))  # 0

