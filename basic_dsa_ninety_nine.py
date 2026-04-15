"""
Basic DSA - Binary Tree Right Side View
Return the values of the nodes you can see from the right side, ordered from top to bottom.
"""

from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def right_side_view(root):
    """
    Level order BFS; after processing each level, the last node seen is the rightmost.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not root:
        return []

    out = []
    q = deque([root])
    while q:
        level_len = len(q)
        for i in range(level_len):
            node = q.popleft()
            if i == level_len - 1:
                out.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Tree Right Side View")
    print("=" * 60)

    #       1
    #     /   \
    #    2     3
    #     \     \
    #      5     4
    root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3, None, TreeNode(4)))
    print(right_side_view(root))  # [1, 3, 4]
