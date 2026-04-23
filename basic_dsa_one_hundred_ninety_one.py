"""
Basic DSA - Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is
non-negative.
"""


def rotate(nums, k):
    """
    Reverse parts:
    - reverse whole array
    - reverse first k
    - reverse rest
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    if n == 0:
        return nums
    k %= n

    def rev(i, j):
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

    rev(0, n - 1)
    rev(0, k - 1)
    rev(k, n - 1)
    return nums


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Rotate Array")
    print("=" * 60)

    a = [1, 2, 3, 4, 5, 6, 7]
    rotate(a, 3)
    print(a)  # [5, 6, 7, 1, 2, 3, 4]

    b = [-1, -100, 3, 99]
    rotate(b, 2)
    print(b)  # [3, 99, -1, -100]
