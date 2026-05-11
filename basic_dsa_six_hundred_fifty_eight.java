/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_eight {

    // Problem 1: Minimum Depth of Binary Tree
    // Shortest path from root down to a leaf (node with no children), counted in nodes.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * If one child missing, only the other side can hold shortest path to a leaf
     * Time Complexity: O(n)
     * Space Complexity: O(h)
     */
    public static int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null) {
            return 1 + minDepth(root.right);
        }
        if (root.right == null) {
            return 1 + minDepth(root.left);
        }
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Minimum Depth of Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println("3,9,20,... -> " + minDepth(root));

        TreeNode skew = new TreeNode(2);
        skew.right = new TreeNode(3);
        skew.right.right = new TreeNode(4);
        System.out.println("right chain -> " + minDepth(skew));

        System.out.println("null -> " + minDepth(null));
    }
}
