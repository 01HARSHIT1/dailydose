"""
Basic DSA - Excel Sheet Column Number
Given a column title as appears in an Excel sheet, return its corresponding column number.
"""


def title_to_number(column_title):
    """
    Base-26 conversion with 'A' -> 1 ... 'Z' -> 26.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    num = 0
    for ch in column_title:
        num = num * 26 + (ord(ch) - ord("A") + 1)
    return num


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Excel Sheet Column Number")
    print("=" * 60)

    print(title_to_number("A"))   # 1
    print(title_to_number("AB"))  # 28
    print(title_to_number("ZY"))  # 701

