/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_three {

    // Problem 1: Symmetric Tree
    // Root's left subtree is the mirror of its right subtree.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Two pointers: left branch goes out-in, right branch goes in-out
     * Time Complexity: O(n)
     * Space Complexity: O(h) stack
     */
    public static boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return mirror(root.left, root.right);
    }

    private static boolean mirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null) {
            return false;
        }
        return a.val == b.val && mirror(a.left, b.right) && mirror(a.right, b.left);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Symmetric Tree");
        System.out.println("=".repeat(60));

        TreeNode ok = new TreeNode(1);
        ok.left = new TreeNode(2);
        ok.right = new TreeNode(2);
        ok.left.left = new TreeNode(3);
        ok.left.right = new TreeNode(4);
        ok.right.left = new TreeNode(4);
        ok.right.right = new TreeNode(3);
        System.out.println("symmetric -> " + isSymmetric(ok));

        TreeNode bad = new TreeNode(1);
        bad.left = new TreeNode(2);
        bad.right = new TreeNode(2);
        bad.left.right = new TreeNode(3);
        bad.right.right = new TreeNode(3);
        System.out.println("not symmetric -> " + isSymmetric(bad));

        System.out.println("null -> " + isSymmetric(null));
    }
}
