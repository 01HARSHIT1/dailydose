"""
Basic DSA - Longest Substring with At Most Two Distinct Characters
Given a string s, return the length of the longest substring that contains at most
two distinct characters.
"""


def length_of_longest_substring_two_distinct(s):
    """
    Sliding window with char counts.
    Time Complexity: O(n)
    Space Complexity: O(1) (bounded by alphabet size)
    """
    counts = {}
    left = 0
    best = 0
    for right, ch in enumerate(s):
        counts[ch] = counts.get(ch, 0) + 1
        while len(counts) > 2:
            left_ch = s[left]
            counts[left_ch] -= 1
            if counts[left_ch] == 0:
                del counts[left_ch]
            left += 1
        best = max(best, right - left + 1)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Substring with At Most Two Distinct Characters")
    print("=" * 60)

    print(length_of_longest_substring_two_distinct("eceba"))  # 3 ("ece")
    print(length_of_longest_substring_two_distinct("ccaabbb"))  # 5 ("aabbb")
