"""
Basic DSA - Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon has a number on it.
If you burst balloon i, you get nums[i - 1] * nums[i] * nums[i + 1] coins.
After bursting, balloon i disappears. Return the maximum coins you can collect.
"""


def max_coins(nums):
    """
    Interval DP.
    Let dp[l][r] be max coins from bursting balloons strictly inside (l, r).
    Time Complexity: O(n^3)
    Space Complexity: O(n^2)
    """
    arr = [1] + nums + [1]
    n = len(arr)
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n):  # interval size
        for l in range(0, n - length):
            r = l + length
            best = 0
            for k in range(l + 1, r):
                best = max(
                    best,
                    dp[l][k] + dp[k][r] + arr[l] * arr[k] * arr[r],
                )
            dp[l][r] = best

    return dp[0][n - 1]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Burst Balloons")
    print("=" * 60)

    print(max_coins([3, 1, 5, 8]))  # 167
    print(max_coins([1, 5]))  # 10
