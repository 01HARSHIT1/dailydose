"""
Basic DSA - Lowest Common Ancestor of a Binary Search Tree
Given a BST, find the lowest common ancestor (LCA) of two given nodes in the BST.
"""


class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"TreeNode({self.val})"


def lowest_common_ancestor_bst(root, p, q):
    """
    Use BST ordering to walk down from root.

    Time Complexity: O(h) where h is tree height
    Space Complexity: O(1)
    """
    if root is None or p is None or q is None:
        return None

    a = p.val
    b = q.val
    cur = root
    while cur is not None:
        if a < cur.val and b < cur.val:
            cur = cur.left
        elif a > cur.val and b > cur.val:
            cur = cur.right
        else:
            return cur
    return None


def _bst_insert(root, val):
    if root is None:
        return TreeNode(val)
    cur = root
    while True:
        if val < cur.val:
            if cur.left is None:
                cur.left = TreeNode(val)
                return root
            cur = cur.left
        else:
            if cur.right is None:
                cur.right = TreeNode(val)
                return root
            cur = cur.right


def _bst_find(root, val):
    cur = root
    while cur is not None:
        if val == cur.val:
            return cur
        cur = cur.left if val < cur.val else cur.right
    return None


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Lowest Common Ancestor of a BST")
    print("=" * 60)

    # Build BST:      6
    #              /     \
    #             2       8
    #           /   \   /   \
    #          0     4 7     9
    #               / \
    #              3   5
    root = None
    for v in [6, 2, 8, 0, 4, 7, 9, 3, 5]:
        root = _bst_insert(root, v)

    p = _bst_find(root, 2)
    q = _bst_find(root, 8)
    print(lowest_common_ancestor_bst(root, p, q).val)  # 6

    p2 = _bst_find(root, 2)
    q2 = _bst_find(root, 4)
    print(lowest_common_ancestor_bst(root, p2, q2).val)  # 2
