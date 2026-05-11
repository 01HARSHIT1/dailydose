/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty {

    // Problem 1: Maximum Depth of Binary Tree
    // Root-to-leaf length in edges is depth; return max depth (empty tree -> 0).

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Post-order: depth = 1 + max(left depth, right depth)
     * Time Complexity: O(n)
     * Space Complexity: O(h) recursion stack, h = height
     */
    public static int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Maximum Depth of Binary Tree");
        System.out.println("=".repeat(60));

        System.out.println("null -> " + maxDepth(null));

        TreeNode single = new TreeNode(1);
        System.out.println("single -> " + maxDepth(single));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println("classic -> " + maxDepth(root));
    }
}
