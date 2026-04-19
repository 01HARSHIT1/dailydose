"""
Basic DSA - Sort Array By Parity
Given an integer array nums, move all even integers to the front of odd integers.
Return any array that satisfies this condition.
"""


def sort_array_by_parity(nums):
    """
    Two pointers from both ends; swap when left is odd and right is even.
    Time Complexity: O(n)
    Space Complexity: O(1) extra
    """
    left, right = 0, len(nums) - 1
    while left < right:
        if nums[left] % 2 == 0:
            left += 1
        elif nums[right] % 2 == 1:
            right -= 1
        else:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
    return nums


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Sort Array By Parity")
    print("=" * 60)

    a = [3, 1, 2, 4]
    print(sort_array_by_parity(a))  # e.g. [4, 2, 1, 3] or [2, 4, 3, 1]
