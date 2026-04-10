"""
Basic DSA - Rotate Array
Rotate the array to the right by k steps in-place.
"""


def rotate(nums, k):
    """
    Reverse three segments: whole, first k, rest.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    if n == 0:
        return nums
    k %= n
    if k == 0:
        return nums

    def reverse(i, j):
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

    reverse(0, n - 1)
    reverse(0, k - 1)
    reverse(k, n - 1)
    return nums


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotate Array")
    print("=" * 60)

    tests = [
        ([1, 2, 3, 4, 5, 6, 7], 3, [5, 6, 7, 1, 2, 3, 4]),
        ([-1, -100, 3, 99], 2, [3, 99, -1, -100]),
        ([1], 5, [1]),
        ([1, 2], 0, [1, 2]),
    ]

    for arr, k, expected in tests:
        original = arr[:]
        got = rotate(arr, k)
        print(f"nums={original}, k={k} -> {got} (expected {expected})")
