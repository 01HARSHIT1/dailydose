"""
Basic DSA - Find the Town Judge
In a town of n people labeled 1..n, a town judge is defined as:
- The judge trusts nobody.
- Everybody (except the judge) trusts the judge.

Given n and an array trust where trust[i] = [a, b] means a trusts b,
return the judge's label if they exist, else -1.
"""


def find_judge(n, trust):
    """
    Use indegree/outdegree counts.
    Time Complexity: O(n + len(trust))
    Space Complexity: O(n)
    """
    indeg = [0] * (n + 1)
    outdeg = [0] * (n + 1)
    for a, b in trust:
        outdeg[a] += 1
        indeg[b] += 1

    for person in range(1, n + 1):
        if outdeg[person] == 0 and indeg[person] == n - 1:
            return person
    return -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find the Town Judge")
    print("=" * 60)

    print(find_judge(2, [[1, 2]]))  # 2
    print(find_judge(3, [[1, 3], [2, 3]]))  # 3
    print(find_judge(3, [[1, 3], [2, 3], [3, 1]]))  # -1
