"""
Basic DSA - Path Sum
Given the root of a binary tree and an integer targetSum, return True if the tree has a root-to-leaf path
such that adding up all the values along the path equals targetSum.
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def has_path_sum(root, target_sum):
    """
    DFS accumulate remaining sum.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    if not root:
        return False
    if not root.left and not root.right:
        return root.val == target_sum
    remaining = target_sum - root.val
    return has_path_sum(root.left, remaining) or has_path_sum(root.right, remaining)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Path Sum")
    print("=" * 60)

    #       5
    #      / \
    #     4   8
    #    /   / \
    #   11  13  4
    #  /  \      \
    # 7    2      1
    root = TreeNode(
        5,
        TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))),
        TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))),
    )
    print(has_path_sum(root, 22))  # True
    print(has_path_sum(root, 26))  # True (5->8->13)
    print(has_path_sum(root, 18))  # True (5->8->4->1)

