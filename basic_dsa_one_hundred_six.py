"""
Basic DSA - Same Tree
Determine if two binary trees are structurally identical and have the same node values.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_same_tree(p, q):
    """
    Recursive compare.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """
    if not p and not q:
        return True
    if not p or not q:
        return False
    if p.val != q.val:
        return False
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Same Tree")
    print("=" * 60)

    a = TreeNode(1, TreeNode(2), TreeNode(3))
    b = TreeNode(1, TreeNode(2), TreeNode(3))
    c = TreeNode(1, TreeNode(2), TreeNode(4))

    print(is_same_tree(a, b))  # True
    print(is_same_tree(a, c))  # False

