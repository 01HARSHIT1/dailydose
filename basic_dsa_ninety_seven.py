"""
Basic DSA - Validate Binary Search Tree
Determine if a binary tree is a valid BST.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_valid_bst(root):
    """
    Each node must be strictly inside (min, max) bounds inherited from ancestors.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """

    def dfs(node, lo, hi):
        if not node:
            return True
        if not (lo < node.val < hi):
            return False
        return dfs(node.left, lo, node.val) and dfs(node.right, node.val, hi)

    return dfs(root, float("-inf"), float("inf"))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Validate Binary Search Tree")
    print("=" * 60)

    good = TreeNode(2, TreeNode(1), TreeNode(3))
    print(is_valid_bst(good))  # True

    bad = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    print(is_valid_bst(bad))  # False (3 is in wrong subtree for 5)
