"""
Basic DSA - Minimum Window Substring
Given two strings s and t, return the minimum window substring of s such that every
character in t (including duplicates) is included in the window. If no such substring,
return "".
"""


def min_window(s, t):
    """
    Sliding window with character counts.
    Time Complexity: O(len(s) + len(t))
    Space Complexity: O(k) where k is distinct chars in t
    """
    if not t or not s:
        return ""

    need = {}
    for ch in t:
        need[ch] = need.get(ch, 0) + 1
    required = len(need)

    window = {}
    formed = 0
    l = 0
    best_len = float("inf")
    best_l = 0

    for r, ch in enumerate(s):
        window[ch] = window.get(ch, 0) + 1
        if ch in need and window[ch] == need[ch]:
            formed += 1

        while l <= r and formed == required:
            if r - l + 1 < best_len:
                best_len = r - l + 1
                best_l = l

            left_ch = s[l]
            window[left_ch] -= 1
            if left_ch in need and window[left_ch] < need[left_ch]:
                formed -= 1
            l += 1

    return "" if best_len == float("inf") else s[best_l : best_l + best_len]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Window Substring")
    print("=" * 60)

    print(min_window("ADOBECODEBANC", "ABC"))  # BANC
    print(min_window("a", "a"))  # a
    print(min_window("a", "aa"))  # ""
