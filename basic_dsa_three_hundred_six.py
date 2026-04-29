"""
Basic DSA - Additive Number
An additive number is a string whose digits can form an additive sequence:
the sum of first two numbers equals the third, and so on.
Numbers in the sequence cannot have leading zeros unless the number is zero itself.
Given a string num, return True if it's additive.
"""


def is_additive_number(num):
    """
    Try all first/second splits, then validate by iterative string-sum matching.
    Time Complexity: O(n^3) worst case
    Space Complexity: O(n)
    """
    n = len(num)

    for i in range(1, n):
        for j in range(i + 1, n):
            a = num[:i]
            b = num[i:j]
            if (len(a) > 1 and a[0] == "0") or (len(b) > 1 and b[0] == "0"):
                continue
            x, y = int(a), int(b)
            k = j
            while k < n:
                s = x + y
                s_str = str(s)
                if not num.startswith(s_str, k):
                    break
                k += len(s_str)
                x, y = y, s
            if k == n:
                return True

    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Additive Number")
    print("=" * 60)

    print(is_additive_number("112358"))  # True
    print(is_additive_number("199100199"))  # True
    print(is_additive_number("1023"))  # False
