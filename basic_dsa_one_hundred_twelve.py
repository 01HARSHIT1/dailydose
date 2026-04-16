"""
Basic DSA - Zigzag Level Order Traversal
Return the zigzag (alternating left-to-right and right-to-left) level order traversal of a binary tree.
"""

from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def zigzag_level_order(root):
    """
    BFS by levels; reverse each alternate level.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not root:
        return []

    result = []
    q = deque([root])
    left_to_right = True

    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if not left_to_right:
            level.reverse()
        result.append(level)
        left_to_right = not left_to_right

    return result


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Zigzag Level Order Traversal")
    print("=" * 60)

    #        3
    #      /   \
    #     9     20
    #          /  \
    #         15   7
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(zigzag_level_order(root))  # [[3],[20,9],[15,7]]
    print(zigzag_level_order(None))  # []

