"""
Basic DSA - Roman to Integer
Convert a Roman numeral to an integer.
"""


def roman_to_int(s):
    """
    Scan left-to-right; if current value < next value, subtract, else add.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    val = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    total = 0
    for i, ch in enumerate(s):
        cur = val[ch]
        nxt = val[s[i + 1]] if i + 1 < len(s) else 0
        total += -cur if cur < nxt else cur
    return total


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Roman to Integer")
    print("=" * 60)

    print(roman_to_int("III"))  # 3
    print(roman_to_int("LVIII"))  # 58
    print(roman_to_int("MCMXCIV"))  # 1994
