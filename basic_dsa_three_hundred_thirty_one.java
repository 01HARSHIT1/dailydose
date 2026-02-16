/**
 * Basic DSA Problems - Symmetric Tree
 * Check if binary tree is mirror of itself
 */
public class basic_dsa_three_hundred_thirty_one {

    // Problem: Root of binary tree. Return true if tree is symmetric (mirror around center).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Two mirrors compared recursively: left.left vs right.right, left.right vs right.left.
     * Time O(n), Space O(h)
     */
    public static boolean isSymmetric(TreeNode root) {
        return root == null || mirror(root.left, root.right);
    }

    static boolean mirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        return a.val == b.val && mirror(a.left, b.right) && mirror(a.right, b.left);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Symmetric Tree");
        System.out.println("=".repeat(60));

        TreeNode a = new TreeNode(1);
        a.left = new TreeNode(2);
        a.right = new TreeNode(2);
        a.left.left = new TreeNode(3);
        a.left.right = new TreeNode(4);
        a.right.left = new TreeNode(4);
        a.right.right = new TreeNode(3);
        System.out.println("[1,2,2,3,4,4,3] -> " + isSymmetric(a));

        TreeNode b = new TreeNode(1);
        b.left = new TreeNode(2);
        b.right = new TreeNode(2);
        b.left.right = new TreeNode(3);
        b.right.right = new TreeNode(3);
        System.out.println("[1,2,2,null,3,null,3] -> " + isSymmetric(b));
    }
}
