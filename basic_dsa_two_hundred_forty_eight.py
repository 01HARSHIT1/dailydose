"""
Basic DSA - Longest Substring with At Most K Distinct Characters
Given a string s and an integer k, return the length of the longest substring that
contains at most k distinct characters.
"""


def length_of_longest_substring_k_distinct(s, k):
    """
    Sliding window with char counts.
    Time Complexity: O(n)
    Space Complexity: O(1) (bounded by alphabet size)
    """
    if k <= 0 or not s:
        return 0
    counts = {}
    left = 0
    best = 0
    for right, ch in enumerate(s):
        counts[ch] = counts.get(ch, 0) + 1
        while len(counts) > k:
            left_ch = s[left]
            counts[left_ch] -= 1
            if counts[left_ch] == 0:
                del counts[left_ch]
            left += 1
        best = max(best, right - left + 1)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Substring with At Most K Distinct Characters")
    print("=" * 60)

    print(length_of_longest_substring_k_distinct("eceba", 2))  # 3
    print(length_of_longest_substring_k_distinct("aa", 1))  # 2
