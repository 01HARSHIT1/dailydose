"""
Basic DSA - Two Sum II (Input Array Is Sorted)
Given a 1-indexed sorted array of integers numbers, find two numbers such that they
add up to a specific target number and return their indices [i, j] (1-indexed).
Assume there is exactly one solution and you may not use the same element twice.
"""


def two_sum_ii(numbers, target):
    """
    Two pointers moving inward based on sum.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    i, j = 0, len(numbers) - 1
    while i < j:
        s = numbers[i] + numbers[j]
        if s == target:
            return [i + 1, j + 1]
        if s < target:
            i += 1
        else:
            j -= 1
    return [-1, -1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Two Sum II (Sorted Input)")
    print("=" * 60)

    print(two_sum_ii([2, 7, 11, 15], 9))  # [1, 2]
    print(two_sum_ii([2, 3, 4], 6))  # [1, 3]
