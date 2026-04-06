"""
Basic DSA - Two Sum
Return indices of the two numbers such that they add up to a specific target.
"""


def two_sum(nums, target):
    """
    Hash map of value -> index.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    seen = {}
    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return [seen[need], i]
        seen[x] = i
    return []


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Two Sum")
    print("=" * 60)

    tests = [
        ([2, 7, 11, 15], 9, [0, 1]),
        ([3, 2, 4], 6, [1, 2]),
        ([3, 3], 6, [0, 1]),
        ([], 10, []),
        ([1, 2, 3], 7, []),
    ]

    for nums, target, expected in tests:
        got = two_sum(nums, target)
        print(f"nums={nums}, target={target} -> {got} (expected {expected})")

