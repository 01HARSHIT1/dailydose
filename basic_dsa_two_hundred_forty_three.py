"""
Basic DSA - Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the
width of each bar is 1, return the area of the largest rectangle in the histogram.
"""


def largest_rectangle_area(heights):
    """
    Monotonic increasing stack of (start_index, height).
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    best = 0
    stack = []
    for i, h in enumerate(heights + [0]):  # sentinel to flush
        start = i
        while stack and stack[-1][1] > h:
            start, height = stack.pop()
            best = max(best, height * (i - start))
        stack.append((start, h))
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Largest Rectangle in Histogram")
    print("=" * 60)

    print(largest_rectangle_area([2, 1, 5, 6, 2, 3]))  # 10
    print(largest_rectangle_area([2, 4]))  # 4
