"""
Basic DSA - Majority Element
Return the element that appears more than ⌊n/2⌋ times.
"""


def majority_element(nums):
    """
    Boyer-Moore voting algorithm.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    candidate = None
    count = 0
    for x in nums:
        if count == 0:
            candidate = x
            count = 1
        elif x == candidate:
            count += 1
        else:
            count -= 1
    return candidate


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Majority Element")
    print("=" * 60)

    print(majority_element([3, 2, 3]))  # 3
    print(majority_element([2, 2, 1, 1, 1, 2, 2]))  # 2

