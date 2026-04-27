"""
Basic DSA - Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string
and change it to any other uppercase English character at most k times.
Return the length of the longest substring containing the same letter you can get.
"""


def character_replacement(s, k):
    """
    Sliding window with counts; keep window valid if (window_len - max_freq) <= k.
    Time Complexity: O(n)
    Space Complexity: O(1) (bounded by alphabet size)
    """
    counts = {}
    left = 0
    max_freq = 0
    best = 0

    for right, ch in enumerate(s):
        counts[ch] = counts.get(ch, 0) + 1
        max_freq = max(max_freq, counts[ch])

        while (right - left + 1) - max_freq > k:
            left_ch = s[left]
            counts[left_ch] -= 1
            left += 1

        best = max(best, right - left + 1)

    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Repeating Character Replacement")
    print("=" * 60)

    print(character_replacement("ABAB", 2))  # 4
    print(character_replacement("AABABBA", 1))  # 4
