"""
Basic DSA - Subsets
Return the power set of nums (all subsets). The solution set must not contain duplicate subsets.
"""


def subsets(nums):
    """
    Backtracking: at each step, extend with a larger index to avoid duplicates.
    Time Complexity: O(n * 2^n)
    Space Complexity: O(n) recursion depth plus output
    """
    result = []

    def backtrack(start, path):
        result.append(list(path))
        for i in range(start, len(nums)):
            path.append(nums[i])
            backtrack(i + 1, path)
            path.pop()

    backtrack(0, [])
    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Subsets")
    print("=" * 60)

    for nums in [[1, 2, 3], [0], []]:
        out = subsets(nums)
        print(f"nums={nums} -> {len(out)} subsets: {out}")
