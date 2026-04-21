"""
Basic DSA - Next Greater Element I
Given two arrays nums1 and nums2 where nums1 is a subset of nums2, find the next
greater element for each value in nums1 based on its position in nums2.
If no greater element exists, return -1 for that value.
"""


def next_greater_element(nums1, nums2):
    """
    Monotonic decreasing stack to compute next-greater map for nums2.
    Time Complexity: O(n + m)
    Space Complexity: O(n)
    """
    next_greater = {}
    stack = []
    for x in nums2:
        while stack and stack[-1] < x:
            next_greater[stack.pop()] = x
        stack.append(x)
    for x in stack:
        next_greater[x] = -1
    return [next_greater[x] for x in nums1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Next Greater Element I")
    print("=" * 60)

    print(next_greater_element([4, 1, 2], [1, 3, 4, 2]))  # [-1, 3, -1]
    print(next_greater_element([2, 4], [1, 2, 3, 4]))  # [3, -1]
