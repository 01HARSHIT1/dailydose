"""
Basic DSA - 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to target. Return the sum.
Assume exactly one solution.
"""


def three_sum_closest(nums, target):
    """
    Sort + two pointers; track best sum by absolute difference.
    Time Complexity: O(n^2)
    Space Complexity: O(1) extra
    """
    nums.sort()
    best = nums[0] + nums[1] + nums[2]
    n = len(nums)
    for i in range(n - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        l, r = i + 1, n - 1
        while l < r:
            s = nums[i] + nums[l] + nums[r]
            if abs(s - target) < abs(best - target):
                best = s
            if s == target:
                return s
            if s < target:
                l += 1
            else:
                r -= 1
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: 3Sum Closest")
    print("=" * 60)

    print(three_sum_closest([-1, 2, 1, -4], 1))  # 2
    print(three_sum_closest([0, 0, 0], 1))  # 0
