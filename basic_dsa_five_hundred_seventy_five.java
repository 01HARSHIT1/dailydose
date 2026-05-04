/**
 * Basic DSA Problems - One Fundamental Tree Traversal Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_five {

    // Problem 1: Maximum Depth of Binary Tree
    // Given the root of a binary tree, return its maximum depth.
    // The maximum depth is the number of nodes along the longest path
    // from the root node down to the farthest leaf node.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Recursive depth-first traversal
     * Time Complexity: O(n)
     * Space Complexity: O(h), h = tree height
     */
    public static Integer maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return 1 + Math.max(leftDepth, rightDepth);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Maximum Depth of Binary Tree");
        System.out.println("=".repeat(60));

        // Tree: [3,9,20,null,null,15,7]
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println("depth([3,9,20,null,null,15,7]) -> " + maxDepth(root));

        TreeNode single = new TreeNode(1);
        System.out.println("depth([1]) -> " + maxDepth(single));

        System.out.println("depth([]) -> " + maxDepth(null));
    }
}
