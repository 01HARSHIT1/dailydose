"""
Basic DSA - Minimum Depth of Binary Tree
Return the minimum depth from the root down to the nearest leaf node.
"""

from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def min_depth(root):
    """
    BFS: first leaf encountered gives minimum depth.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not root:
        return 0

    q = deque([(root, 1)])
    while q:
        node, d = q.popleft()
        if not node.left and not node.right:
            return d
        if node.left:
            q.append((node.left, d + 1))
        if node.right:
            q.append((node.right, d + 1))
    return 0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Depth of Binary Tree")
    print("=" * 60)

    #       3
    #      / \
    #     9  20
    #        / \
    #       15  7
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(min_depth(root))  # 2
    print(min_depth(None))  # 0

