"""
Basic DSA - Integer to Roman
Convert an integer to a Roman numeral.
Assume 1 <= num <= 3999.
"""


def int_to_roman(num):
    """
    Greedy subtraction using value-symbol pairs.
    Time Complexity: O(1) (bounded by fixed set of symbols)
    Space Complexity: O(1)
    """
    pairs = [
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I"),
    ]
    out = []
    for value, sym in pairs:
        if num == 0:
            break
        q, num = divmod(num, value)
        if q:
            out.append(sym * q)
    return "".join(out)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Integer to Roman")
    print("=" * 60)

    print(int_to_roman(3))  # III
    print(int_to_roman(58))  # LVIII
    print(int_to_roman(1994))  # MCMXCIV
