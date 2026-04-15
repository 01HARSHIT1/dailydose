"""
Basic DSA - Invert Binary Tree
Invert a binary tree (swap every node's left and right subtrees).
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def invert_tree(root):
    """
    Post-order style: invert children, then swap pointers.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """
    if not root:
        return None
    invert_tree(root.left)
    invert_tree(root.right)
    root.left, root.right = root.right, root.left
    return root


def tree_to_list_preorder(root):
    """Serialize shape for demo (preorder with None for missing)."""
    out = []

    def walk(node):
        if not node:
            out.append(None)
            return
        out.append(node.val)
        walk(node.left)
        walk(node.right)

    walk(root)
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Invert Binary Tree")
    print("=" * 60)

    #     4
    #    / \
    #   2   7
    #  / \ / \
    # 1  3 6  9
    root = TreeNode(
        4,
        TreeNode(2, TreeNode(1), TreeNode(3)),
        TreeNode(7, TreeNode(6), TreeNode(9)),
    )
    invert_tree(root)
    print(tree_to_list_preorder(root))
