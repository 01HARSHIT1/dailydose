"""
Basic DSA - Binary Tree Right Side View
Given the root of a binary tree, imagine standing on the right side of it and return
the values of the nodes you can see ordered from top to bottom.
"""

from collections import deque


class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def right_side_view(root):
    """
    Level-order traversal; the last node visited per level is visible from the right.
    Time Complexity: O(n)
    Space Complexity: O(w) (O(n) worst-case)
    """
    if root is None:
        return []

    res = []
    q = deque([root])
    while q:
        level_size = len(q)
        last_val = None
        for _ in range(level_size):
            node = q.popleft()
            last_val = node.val
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)
        res.append(last_val)
    return res


def _build_tree_level_order(values):
    if not values or values[0] is None:
        return None

    it = iter(values)
    root = TreeNode(next(it))
    q = deque([root])
    while q:
        node = q.popleft()
        try:
            left_val = next(it)
        except StopIteration:
            break
        if left_val is not None:
            node.left = TreeNode(left_val)
            q.append(node.left)

        try:
            right_val = next(it)
        except StopIteration:
            break
        if right_val is not None:
            node.right = TreeNode(right_val)
            q.append(node.right)

    return root


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Tree Right Side View")
    print("=" * 60)

    root1 = _build_tree_level_order([1, 2, 3, None, 5, None, 4])
    print(right_side_view(root1))  # [1, 3, 4]

    root2 = _build_tree_level_order([1, None, 3])
    print(right_side_view(root2))  # [1, 3]

    root3 = _build_tree_level_order([])
    print(right_side_view(root3))  # []
