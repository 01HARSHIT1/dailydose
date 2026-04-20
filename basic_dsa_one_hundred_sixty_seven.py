"""
Basic DSA - Add Binary
Given two binary strings a and b, return their sum as a binary string.
"""


def add_binary(a, b):
    """
    Add from the end with carry.
    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
    """
    i, j = len(a) - 1, len(b) - 1
    carry = 0
    out = []
    while i >= 0 or j >= 0 or carry:
        total = carry
        if i >= 0:
            total += ord(a[i]) - ord("0")
            i -= 1
        if j >= 0:
            total += ord(b[j]) - ord("0")
            j -= 1
        out.append("1" if (total & 1) else "0")
        carry = 1 if total >= 2 else 0
    out.reverse()
    return "".join(out)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Add Binary")
    print("=" * 60)

    print(add_binary("11", "1"))  # 100
    print(add_binary("1010", "1011"))  # 10101
