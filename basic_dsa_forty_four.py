"""
Basic DSA - Move Zeroes
Move all zeroes to the end of the list while maintaining the relative order of non-zero elements.
"""


def move_zeroes(nums):
    """
    Two-pointer write index.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    write = 0
    for x in nums:
        if x != 0:
            nums[write] = x
            write += 1

    for i in range(write, len(nums)):
        nums[i] = 0

    return nums


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Move Zeroes")
    print("=" * 60)

    tests = [
        ([0, 1, 0, 3, 12], [1, 3, 12, 0, 0]),
        ([0, 0, 0], [0, 0, 0]),
        ([1, 2, 3], [1, 2, 3]),
        ([], []),
        ([0, -1, 0, 2, 0, 3], [-1, 2, 3, 0, 0, 0]),
    ]

    for nums, expected in tests:
        original = nums[:]
        got = move_zeroes(nums)
        print(f"nums={original} -> {got} (expected {expected})")

