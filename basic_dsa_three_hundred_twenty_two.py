"""
Basic DSA - Kth Smallest Element in a BST
Given the root of a BST and an integer k, return the k-th smallest value (1-indexed).
"""


class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def kth_smallest(root, k):
    """
    Iterative inorder traversal (BST inorder yields sorted values).
    Time Complexity: O(h + k) worst-case O(n)
    Space Complexity: O(h)
    """
    if root is None or k <= 0:
        return None

    stack = []
    cur = root
    seen = 0
    while cur is not None or stack:
        while cur is not None:
            stack.append(cur)
            cur = cur.left
        node = stack.pop()
        seen += 1
        if seen == k:
            return node.val
        cur = node.right
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


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Kth Smallest Element in a BST")
    print("=" * 60)

    root = None
    for v in [5, 3, 6, 2, 4, 1]:
        root = _bst_insert(root, v)

    print(kth_smallest(root, 1))  # 1
    print(kth_smallest(root, 3))  # 3
    print(kth_smallest(root, 6))  # 6
