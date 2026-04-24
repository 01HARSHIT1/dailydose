"""
Basic DSA - Move Zeroes
Move all 0's to the end of the array while maintaining the relative order of the
non-zero elements. Do this in-place.
"""


def move_zeroes(nums):
    """
    Compact non-zeroes to the front, then fill the remainder with zeroes.
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

    a = [0, 1, 0, 3, 12]
    move_zeroes(a)
    print(a)  # [1, 3, 12, 0, 0]

    b = [0]
    move_zeroes(b)
    print(b)  # [0]
