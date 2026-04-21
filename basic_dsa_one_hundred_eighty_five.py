"""
Basic DSA - Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates
in-place such that each unique element appears only once. Return k, the number of
unique elements.

After removing duplicates, the first k elements of nums should hold the result.
"""


def remove_duplicates(nums):
    """
    Two pointers: write index for next unique.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0
    write = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[write] = nums[i]
            write += 1
    return write


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Remove Duplicates from Sorted Array")
    print("=" * 60)

    a = [1, 1, 2]
    k = remove_duplicates(a)
    print(k, a[:k])  # 2 [1, 2]

    b = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k = remove_duplicates(b)
    print(k, b[:k])  # 5 [0, 1, 2, 3, 4]
