"""
Basic DSA - Symmetric Tree
Determine if a binary tree is symmetric around its center.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_symmetric(root):
    """
    Recursively compare left and right subtrees as mirrors.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """
    def mirror(a, b):
        if not a and not b:
            return True
        if not a or not b:
            return False
        return a.val == b.val and mirror(a.left, b.right) and mirror(a.right, b.left)

    return mirror(root.left, root.right) if root else True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Symmetric Tree")
    print("=" * 60)

    # Symmetric
    root1 = TreeNode(
        1,
        TreeNode(2, TreeNode(3), TreeNode(4)),
        TreeNode(2, TreeNode(4), TreeNode(3)),
    )
    print(is_symmetric(root1))  # True

    # Not symmetric
    root2 = TreeNode(
        1,
        TreeNode(2, None, TreeNode(3)),
        TreeNode(2, None, TreeNode(3)),
    )
    print(is_symmetric(root2))  # False

