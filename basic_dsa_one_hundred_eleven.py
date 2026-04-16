"""
Basic DSA - Binary Tree Paths
Return all root-to-leaf paths in a binary tree.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def binary_tree_paths(root):
    """
    DFS build path strings.
    Time Complexity: O(n) nodes, plus path building cost
    Space Complexity: O(h) recursion stack
    """
    if not root:
        return []

    out = []

    def dfs(node, path):
        if not node.left and not node.right:
            out.append(path)
            return
        if node.left:
            dfs(node.left, path + "->" + str(node.left.val))
        if node.right:
            dfs(node.right, path + "->" + str(node.right.val))

    dfs(root, str(root.val))
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Binary Tree Paths")
    print("=" * 60)

    #    1
    #   / \
    #  2   3
    #   \
    #    5
    root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3))
    print(binary_tree_paths(root))  # ["1->2->5", "1->3"]
    print(binary_tree_paths(None))  # []

