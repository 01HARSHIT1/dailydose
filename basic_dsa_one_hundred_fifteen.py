"""
Basic DSA - Find the Town Judge
In a town of n people labeled 1..n, the town judge is the person who:
- trusts nobody
- is trusted by everyone else
Return the label of the judge, or -1 if no judge exists.
"""


def find_judge(n, trust):
    """
    Use indegree-outdegree score.
    Time Complexity: O(n + m)
    Space Complexity: O(n)
    """
    score = [0] * (n + 1)
    for a, b in trust:
        score[a] -= 1
        score[b] += 1

    for i in range(1, n + 1):
        if score[i] == n - 1:
            return i
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find the Town Judge")
    print("=" * 60)

    print(find_judge(2, [[1, 2]]))  # 2
    print(find_judge(3, [[1, 3], [2, 3]]))  # 3
    print(find_judge(3, [[1, 3], [2, 3], [3, 1]]))  # -1
    print(find_judge(1, []))  # 1

