"""
Basic DSA - Permutations
Return all permutations of distinct integers nums.
"""


def permute(nums):
    """
    Backtracking with a used array.
    Time Complexity: O(n * n!)
    Space Complexity: O(n) recursion plus output
    """
    n = len(nums)
    result = []
    path = []
    used = [False] * n

    def backtrack():
        if len(path) == n:
            result.append(list(path))
            return
        for i in range(n):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            backtrack()
            path.pop()
            used[i] = False

    backtrack()
    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Permutations")
    print("=" * 60)

    print(permute([1, 2, 3]))
    print(len(permute([1, 2, 3, 4])))
