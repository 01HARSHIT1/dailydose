"""
Basic DSA - Kth Smallest Element in a BST
Return the kth smallest value (1-indexed) in a BST.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def kth_smallest(root, k):
    """
    Iterative inorder traversal yields sorted order for BST.
    Time Complexity: O(h + k)
    Space Complexity: O(h)
    """
    stack = []
    cur = root

    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        k -= 1
        if k == 0:
            return cur.val
        cur = cur.right
    return None


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Kth Smallest Element in a BST")
    print("=" * 60)

    #      5
    #     / \
    #    3   6
    #   / \
    #  2   4
    # /
    #1
    root = TreeNode(
        5,
        TreeNode(3, TreeNode(2, TreeNode(1)), TreeNode(4)),
        TreeNode(6),
    )
    print(kth_smallest(root, 3))  # 3
    print(kth_smallest(root, 1))  # 1

