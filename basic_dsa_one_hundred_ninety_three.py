"""
Basic DSA - Reverse String
Write a function that reverses a string. The input string is given as an array of
characters s. Reverse the array in-place.
"""


def reverse_string(s):
    """
    Two pointers swap.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    i, j = 0, len(s) - 1
    while i < j:
        s[i], s[j] = s[j], s[i]
        i += 1
        j -= 1
    return s


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Reverse String")
    print("=" * 60)

    a = ["h", "e", "l", "l", "o"]
    reverse_string(a)
    print(a)  # ['o', 'l', 'l', 'e', 'h']

    b = ["H", "a", "n", "n", "a", "h"]
    reverse_string(b)
    print(b)  # ['h', 'a', 'n', 'n', 'a', 'H']
