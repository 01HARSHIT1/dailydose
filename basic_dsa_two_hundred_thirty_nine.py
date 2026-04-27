"""
Basic DSA - Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive
elements sequence.
You must write an algorithm that runs in O(n) time.
"""


def longest_consecutive(nums):
    """
    Use a set; only start counting from numbers that are starts of sequences.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    s = set(nums)
    best = 0
    for x in s:
        if x - 1 not in s:
            cur = x
            length = 1
            while cur + 1 in s:
                cur += 1
                length += 1
            best = max(best, length)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Longest Consecutive Sequence")
    print("=" * 60)

    print(longest_consecutive([100, 4, 200, 1, 3, 2]))  # 4
    print(longest_consecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]))  # 9
