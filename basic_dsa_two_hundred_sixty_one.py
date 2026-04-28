"""
Basic DSA - Decode String
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where encoded_string inside the square brackets
is repeated exactly k times. You may assume input is valid and digits are only for repeat counts.
"""


def decode_string(s):
    """
    Stack of (previous_string, repeat_count).
    Time Complexity: O(n) (plus output size)
    Space Complexity: O(n)
    """
    stack = []
    cur = []
    num = 0
    for ch in s:
        if ch.isdigit():
            num = num * 10 + (ord(ch) - ord("0"))
        elif ch == "[":
            stack.append(("".join(cur), num))
            cur = []
            num = 0
        elif ch == "]":
            prev, k = stack.pop()
            cur = [prev + ("".join(cur) * k)]
        else:
            cur.append(ch)
    return "".join(cur)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Decode String")
    print("=" * 60)

    print(decode_string("3[a]2[bc]"))  # aaabcbc
    print(decode_string("3[a2[c]]"))  # accaccacc
    print(decode_string("2[abc]3[cd]ef"))  # abcabccdcdcdef
