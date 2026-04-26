"""
Basic DSA - Container With Most Water
Given n non-negative integers height where each represents a point at coordinate (i, height[i]),
find two lines that together with the x-axis form a container such that the container contains
the most water. Return the maximum amount of water.
"""


def max_area(height):
    """
    Two pointers: move the shorter side inward.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    i, j = 0, len(height) - 1
    best = 0
    while i < j:
        h = height[i] if height[i] < height[j] else height[j]
        best = max(best, h * (j - i))
        if height[i] < height[j]:
            i += 1
        else:
            j -= 1
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Container With Most Water")
    print("=" * 60)

    print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # 49
    print(max_area([1, 1]))  # 1
