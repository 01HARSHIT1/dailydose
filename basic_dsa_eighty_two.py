"""
Basic DSA - Combination Sum
Given distinct positive integers candidates and a target, return all unique combinations
where the chosen numbers sum to target. The same number may be chosen unlimited times.
"""


def combination_sum(candidates, target):
    """
    Sort candidates, then backtrack with index to avoid duplicate orderings.
    Time Complexity: O(2^k) worst case branching (k related to target/min candidate)
    Space Complexity: O(target / min) for recursion depth in worst case
    """
    candidates.sort()
    result = []

    def backtrack(start, remain, path):
        if remain == 0:
            result.append(list(path))
            return
        for i in range(start, len(candidates)):
            x = candidates[i]
            if x > remain:
                break
            path.append(x)
            backtrack(i, remain - x, path)
            path.pop()

    backtrack(0, target, [])
    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Combination Sum")
    print("=" * 60)

    print(combination_sum([2, 3, 6, 7], 7))
    print(combination_sum([2, 3, 5], 8))
