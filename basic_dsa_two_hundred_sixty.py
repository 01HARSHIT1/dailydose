"""
Basic DSA - Maximum Swap
Given an integer num, you can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.
"""


def maximum_swap(num):
    """
    Track last index of each digit, then swap first place where a bigger digit exists later.
    Time Complexity: O(d) where d is number of digits
    Space Complexity: O(1)
    """
    digits = list(str(num))
    last = [-1] * 10
    for i, ch in enumerate(digits):
        last[ord(ch) - ord("0")] = i

    for i, ch in enumerate(digits):
        cur = ord(ch) - ord("0")
        for d in range(9, cur, -1):
            j = last[d]
            if j > i:
                digits[i], digits[j] = digits[j], digits[i]
                return int("".join(digits))
    return num


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Maximum Swap")
    print("=" * 60)

    print(maximum_swap(2736))  # 7236
    print(maximum_swap(9973))  # 9973
