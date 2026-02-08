/**
 * Basic DSA Problems - Balanced Binary Tree
 * Check if tree is height-balanced (|left height - right height| <= 1 at every node)
 */
public class basic_dsa_one_hundred_sixty_three {

    // Problem: Return true if for every node, heights of left and right subtrees differ by at most 1.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Return height; if any subtree is unbalanced, propagate -1. Else check |L-R| <= 1.
     * Time O(n), Space O(h)
     */
    public static boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    static int height(TreeNode node) {
        if (node == null) return 0;
        int L = height(node.left);
        if (L == -1) return -1;
        int R = height(node.right);
        if (R == -1) return -1;
        if (Math.abs(L - R) > 1) return -1;
        return 1 + Math.max(L, R);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Balanced Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("isBalanced -> " + isBalanced(root));
    }
}
