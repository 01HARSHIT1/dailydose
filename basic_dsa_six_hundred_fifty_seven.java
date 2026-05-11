/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_seven {

    // Problem 1: Balanced Binary Tree
    // Height difference between left and right child of every node is at most 1.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Return height or -1 if subtree is unbalanced (early exit)
     * Time Complexity: O(n)
     * Space Complexity: O(h) stack
     */
    public static boolean isBalanced(TreeNode root) {
        return heightOrFail(root) >= 0;
    }

    private static int heightOrFail(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = heightOrFail(root.left);
        if (left < 0) {
            return -1;
        }
        int right = heightOrFail(root.right);
        if (right < 0) {
            return -1;
        }
        if (Math.abs(left - right) > 1) {
            return -1;
        }
        return 1 + Math.max(left, right);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Balanced Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode ok = new TreeNode(3);
        ok.left = new TreeNode(9);
        ok.right = new TreeNode(20);
        ok.right.left = new TreeNode(15);
        ok.right.right = new TreeNode(7);
        System.out.println("classic balanced -> " + isBalanced(ok));

        TreeNode bad = new TreeNode(1);
        bad.left = new TreeNode(2);
        bad.left.left = new TreeNode(3);
        bad.left.left.left = new TreeNode(4);
        System.out.println("left chain -> " + isBalanced(bad));

        System.out.println("null -> " + isBalanced(null));
    }
}
