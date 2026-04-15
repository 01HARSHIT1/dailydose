"""
Basic DSA - Lowest Common Ancestor of a Binary Search Tree
Given a BST, find the lowest common ancestor (LCA) of two nodes.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def lowest_common_ancestor(root, p, q):
    """
    Use BST property: move left/right until split point.
    Time Complexity: O(h)
    Space Complexity: O(1)
    """
    if p.val > q.val:
        p, q = q, p

    cur = root
    while cur:
        if q.val < cur.val:
            cur = cur.left
        elif p.val > cur.val:
            cur = cur.right
        else:
            return cur
    return None


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Lowest Common Ancestor of a BST")
    print("=" * 60)

    #        6
    #      /   \
    #     2     8
    #    / \   / \
    #   0   4 7   9
    #      / \
    #     3   5
    n0 = TreeNode(0)
    n3 = TreeNode(3)
    n5 = TreeNode(5)
    n4 = TreeNode(4, n3, n5)
    n2 = TreeNode(2, n0, n4)
    n7 = TreeNode(7)
    n9 = TreeNode(9)
    n8 = TreeNode(8, n7, n9)
    root = TreeNode(6, n2, n8)

    print(lowest_common_ancestor(root, n2, n8).val)  # 6
    print(lowest_common_ancestor(root, n2, n4).val)  # 2

