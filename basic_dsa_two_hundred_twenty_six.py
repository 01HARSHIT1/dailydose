"""
Basic DSA - 3Sum
Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
The solution set must not contain duplicate triplets.
"""


def three_sum(nums):
    """
    Sort + two pointers, skipping duplicates.
    Time Complexity: O(n^2)
    Space Complexity: O(1) extra (excluding output)
    """
    nums.sort()
    res = []
    n = len(nums)
    for i in range(n - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        if nums[i] > 0:
            break
        l, r = i + 1, n - 1
        while l < r:
            s = nums[i] + nums[l] + nums[r]
            if s == 0:
                res.append([nums[i], nums[l], nums[r]])
                l += 1
                r -= 1
                while l < r and nums[l] == nums[l - 1]:
                    l += 1
                while l < r and nums[r] == nums[r + 1]:
                    r -= 1
            elif s < 0:
                l += 1
            else:
                r -= 1
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: 3Sum")
    print("=" * 60)

    # sort each triplet + overall list for stable output
    out = three_sum([-1, 0, 1, 2, -1, -4])
    print(sorted([sorted(t) for t in out]))  # [[-1, -1, 2], [-1, 0, 1]]
