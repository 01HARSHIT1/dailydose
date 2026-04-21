"""
Basic DSA - Find Smallest Letter Greater Than Target
Given a sorted list of letters and a target letter, return the smallest letter in
the list that is strictly greater than target. Letters wrap around.
"""


def next_greatest_letter(letters, target):
    """
    Binary search for first letter > target. Wrap around using modulo.
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    lo, hi = 0, len(letters)
    while lo < hi:
        mid = (lo + hi) // 2
        if letters[mid] <= target:
            lo = mid + 1
        else:
            hi = mid
    return letters[lo % len(letters)]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find Smallest Letter Greater Than Target")
    print("=" * 60)

    print(next_greatest_letter(["c", "f", "j"], "a"))  # c
    print(next_greatest_letter(["c", "f", "j"], "c"))  # f
    print(next_greatest_letter(["c", "f", "j"], "d"))  # f
    print(next_greatest_letter(["c", "f", "j"], "j"))  # c
