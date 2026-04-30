"""
Basic DSA - Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes'
values (i.e., from left to right, level by level).
"""

from collections import deque


class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def level_order(root):
    """
    BFS with a queue.
    Time Complexity: O(n)
    Space Complexity: O(w) where w is max width of tree (O(n) worst-case)
    """
    if root is None:
        return []

    res = []
    q = deque([root])
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)
        res.append(level)
    return res


def _build_tree_level_order(values):
    """
    Build a binary tree from a list given in level-order where None means missing node.
    Example: [3, 9, 20, None, None, 15, 7]
    """
    if not values:
        return None
    if values[0] is None:
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
    print("Problem: Binary Tree Level Order Traversal")
    print("=" * 60)

    root1 = _build_tree_level_order([3, 9, 20, None, None, 15, 7])
    print(level_order(root1))  # [[3], [9, 20], [15, 7]]

    root2 = _build_tree_level_order([1])
    print(level_order(root2))  # [[1]]

    root3 = _build_tree_level_order([])
    print(level_order(root3))  # []
