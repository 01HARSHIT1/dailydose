"""
Basic DSA - Valid Mountain Array
An array is a mountain if there exists i with strictly increasing values before i
and strictly decreasing values after i. Return whether arr is a valid mountain.
"""


def valid_mountain_array(arr):
    """
    Walk up from the left, then down; must have both an ascent and a descent.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(arr)
    if n < 3:
        return False
    i = 0
    while i + 1 < n and arr[i] < arr[i + 1]:
        i += 1
    if i == 0 or i == n - 1:
        return False
    while i + 1 < n and arr[i] > arr[i + 1]:
        i += 1
    return i == n - 1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Mountain Array")
    print("=" * 60)

    print(valid_mountain_array([2, 1]))  # False
    print(valid_mountain_array([3, 5, 5]))  # False
    print(valid_mountain_array([0, 3, 2, 1]))  # True
