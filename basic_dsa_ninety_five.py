"""
Basic DSA - Binary Tree Level Order Traversal
Return the level order traversal of a binary tree's nodes' values (from left to right, level by level).
"""

from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def level_order(root):
    """
    BFS using a queue.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not root:
        return []

    result = []
    q = deque([root])
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        result.append(level)
    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Tree Level Order Traversal")
    print("=" * 60)

    # Tree:
    #     3
    #    / \
    #   9  20
    #      / \
    #     15  7
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(level_order(root))  # [[3],[9,20],[15,7]]
    print(level_order(None))  # []

