/**
 * Basic DSA Problems - Subtree of Another Tree
 * Check if subRoot is a subtree of root (same structure and values)
 */
public class basic_dsa_one_hundred_sixty_five {

    // Problem: Given roots root and subRoot, return true if subRoot is a subtree of root.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * At each node of root, try matching with subRoot. Use same-tree check when values match.
     * Time O(n*m), Space O(h)
     */
    public static boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (subRoot == null) return true;
        if (root == null) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    static boolean isSame(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null || p.val != q.val) return false;
        return isSame(p.left, q.left) && isSame(p.right, q.right);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Subtree of Another Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(4);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(2);
        TreeNode sub = new TreeNode(4);
        sub.left = new TreeNode(1);
        sub.right = new TreeNode(2);

        System.out.println("isSubtree -> " + isSubtree(root, sub));
    }
}
