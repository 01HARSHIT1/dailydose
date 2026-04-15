"""
Basic DSA - Diameter of Binary Tree
Return the length of the longest path between any two nodes in a tree (number of edges).
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def diameter_of_binary_tree(root):
    """
    One DFS: height(node) returns max depth; update global best with left+right edges through node.
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    """
    best = 0

    def height(node):
        nonlocal best
        if not node:
            return 0
        left = height(node.left)
        right = height(node.right)
        best = max(best, left + right)
        return 1 + max(left, right)

    height(root)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Diameter of Binary Tree")
    print("=" * 60)

    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print(diameter_of_binary_tree(root))  # 3

    print(diameter_of_binary_tree(TreeNode(1)))  # 0
