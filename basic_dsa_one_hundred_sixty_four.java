/**
 * Basic DSA Problems - Same Tree
 * Check if two binary trees are structurally identical with same values
 */
public class basic_dsa_one_hundred_sixty_four {

    // Problem: Given roots of two binary trees p and q, return true if they are the same.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Compare roots (null/val), then recursively compare left and right subtrees.
     * Time O(n), Space O(h)
     */
    public static boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null || p.val != q.val) return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Same Tree");
        System.out.println("=".repeat(60));

        TreeNode p = new TreeNode(1);
        p.left = new TreeNode(2);
        p.right = new TreeNode(3);
        TreeNode q = new TreeNode(1);
        q.left = new TreeNode(2);
        q.right = new TreeNode(3);

        System.out.println("Same tree -> " + isSameTree(p, q));
    }
}
