"""
Basic DSA - Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is in the range
[1, n] inclusive, there is only one repeated number. Return the repeated number.
You must not modify the array and use only constant extra space.
"""


def find_duplicate(nums):
    """
    Floyd's Tortoise and Hare cycle detection.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    slow = nums[0]
    fast = nums[0]
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break

    slow2 = nums[0]
    while slow != slow2:
        slow = nums[slow]
        slow2 = nums[slow2]
    return slow


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find the Duplicate Number")
    print("=" * 60)

    print(find_duplicate([1, 3, 4, 2, 2]))  # 2
    print(find_duplicate([3, 1, 3, 4, 2]))  # 3
