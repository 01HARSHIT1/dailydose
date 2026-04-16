"""
Basic DSA - Balanced Binary Tree
Return True if a binary tree is height-balanced.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_balanced(root):
    """
    Postorder: return height, or -1 if subtree is unbalanced.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    def height(node):
        if not node:
            return 0
        lh = height(node.left)
        if lh == -1:
            return -1
        rh = height(node.right)
        if rh == -1:
            return -1
        if abs(lh - rh) > 1:
            return -1
        return 1 + max(lh, rh)

    return height(root) != -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Balanced Binary Tree")
    print("=" * 60)

    # Balanced:    3
    #            /   \
    #           9    20
    #               /  \
    #              15   7
    balanced = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(is_balanced(balanced))  # True

    # Unbalanced:  1
    #             /
    #            2
    #           /
    #          3
    unbalanced = TreeNode(1, TreeNode(2, TreeNode(3)))
    print(is_balanced(unbalanced))  # False

