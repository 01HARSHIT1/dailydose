"""
Basic DSA - Binary Tree Inorder Traversal (Iterative)
Return the inorder traversal of a binary tree's node values.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def inorder_traversal(root):
    """
    Iterative traversal using a stack.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    out = []
    stack = []
    cur = root

    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        out.append(cur.val)
        cur = cur.right

    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Tree Inorder Traversal (Iterative)")
    print("=" * 60)

    #    1
    #     \
    #      2
    #     /
    #    3
    root = TreeNode(1, None, TreeNode(2, TreeNode(3), None))
    print(inorder_traversal(root))  # [1, 3, 2]
    print(inorder_traversal(None))  # []

