"""
Basic DSA - Min Cost Climbing Stairs
You are given cost where cost[i] is the cost of step i. Once you pay the cost, you
can climb either 1 or 2 steps. You can start from step 0 or 1.
Return the minimum cost to reach the top (beyond the last step).
"""


def min_cost_climbing_stairs(cost):
    """
    DP with rolling variables:
    dp[i] = min cost to reach step i (standing on it).
    Answer is min(dp[n-1], dp[n-2]) to step past end.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(cost)
    if n == 0:
        return 0
    if n == 1:
        return cost[0]

    prev2 = cost[0]
    prev1 = cost[1]
    for i in range(2, n):
        cur = cost[i] + min(prev1, prev2)
        prev2, prev1 = prev1, cur
    return min(prev1, prev2)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Min Cost Climbing Stairs")
    print("=" * 60)

    print(min_cost_climbing_stairs([10, 15, 20]))  # 15
    print(min_cost_climbing_stairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))  # 6
