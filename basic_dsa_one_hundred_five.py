"""
Basic DSA - Maximum Depth of Binary Tree
Return the maximum depth (height) of a binary tree.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def max_depth(root):
    """
    Depth-first recursion.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Maximum Depth of Binary Tree")
    print("=" * 60)

    #      3
    #     / \
    #    9  20
    #       / \
    #      15  7
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(max_depth(root))  # 3
    print(max_depth(None))  # 0

