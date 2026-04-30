"""
Basic DSA - Decode Ways II
An encoding maps 'A'->"1", ..., 'Z'->"26".
The input string s may contain digits and the wildcard '*', where '*' can represent
any digit from '1' to '9'.
Return the number of ways to decode s modulo 10^9+7.
"""


MOD = 1_000_000_007


def num_decodings_ii(s):
    """
    DP with rolling values.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not s:
        return 0

    def ways1(ch):
        if ch == "0":
            return 0
        if ch == "*":
            return 9
        return 1

    def ways2(a, b):
        if a == "*" and b == "*":
            return 15  # 11-19 (9) + 21-26 (6)
        if a == "*":
            if "0" <= b <= "6":
                return 2  # 1b or 2b
            if "7" <= b <= "9":
                return 1  # 1b
            return 0
        if b == "*":
            if a == "1":
                return 9  # 11-19
            if a == "2":
                return 6  # 21-26
            return 0
        two = int(a + b)
        return 1 if 10 <= two <= 26 else 0

    prev2 = 1
    prev1 = ways1(s[0])
    for i in range(1, len(s)):
        cur = (prev1 * ways1(s[i]) + prev2 * ways2(s[i - 1], s[i])) % MOD
        prev2, prev1 = prev1, cur
    return prev1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Decode Ways II")
    print("=" * 60)

    print(num_decodings_ii("*"))  # 9
    print(num_decodings_ii("1*"))  # 18
    print(num_decodings_ii("2*"))  # 15
