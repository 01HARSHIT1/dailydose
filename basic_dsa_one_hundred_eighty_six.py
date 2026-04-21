"""
Basic DSA - Remove Element
Given an integer array nums and an integer val, remove all occurrences of val
in-place. The relative order of the elements may be changed.
Return k, the number of elements not equal to val.
"""


def remove_element(nums, val):
    """
    Write pointer to overwrite elements != val.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    write = 0
    for x in nums:
        if x != val:
            nums[write] = x
            write += 1
    return write


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Remove Element")
    print("=" * 60)

    a = [3, 2, 2, 3]
    k = remove_element(a, 3)
    print(k, sorted(a[:k]))  # 2 [2, 2]

    b = [0, 1, 2, 2, 3, 0, 4, 2]
    k = remove_element(b, 2)
    print(k, sorted(b[:k]))  # 5 [0, 0, 1, 3, 4]
