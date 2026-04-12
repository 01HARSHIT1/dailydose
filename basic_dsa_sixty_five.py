"""
Basic DSA - Container With Most Water
Given n vertical lines at x = 0..n-1 with heights height[i],
find two lines that together with the x-axis form a container with the maximum area.
"""


def max_area(height):
    """
    Two pointers from both ends; move the shorter side inward.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(height) - 1
    best = 0

    while left < right:
        h = min(height[left], height[right])
        best = max(best, h * (right - left))
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Container With Most Water")
    print("=" * 60)

    tests = [
        ([1, 8, 6, 2, 5, 4, 8, 3, 7], 49),
        ([1, 1], 1),
        ([4, 3, 2, 1, 4], 16),
    ]

    for h, expected in tests:
        got = max_area(h)
        print(f"height={h} -> {got} (expected {expected})")
