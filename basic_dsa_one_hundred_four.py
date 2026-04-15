"""
Basic DSA - Merge Two Binary Trees
Given two binary trees, merge them by summing overlapping nodes.
If a node exists in only one tree, use it directly.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def merge_trees(t1, t2):
    """
    Recursive merge.
    Time Complexity: O(n) where n is total nodes visited
    Space Complexity: O(h) recursion stack
    """
    if not t1:
        return t2
    if not t2:
        return t1

    t1.val += t2.val
    t1.left = merge_trees(t1.left, t2.left)
    t1.right = merge_trees(t1.right, t2.right)
    return t1


def preorder(root):
    out = []

    def dfs(node):
        if not node:
            out.append(None)
            return
        out.append(node.val)
        dfs(node.left)
        dfs(node.right)

    dfs(root)
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Two Binary Trees")
    print("=" * 60)

    # Tree 1:      1
    #            /   \
    #           3     2
    #          /
    #         5
    t1 = TreeNode(1, TreeNode(3, TreeNode(5)), TreeNode(2))

    # Tree 2:      2
    #            /   \
    #           1     3
    #            \     \
    #             4     7
    t2 = TreeNode(2, TreeNode(1, None, TreeNode(4)), TreeNode(3, None, TreeNode(7)))

    merged = merge_trees(t1, t2)
    print(preorder(merged))

