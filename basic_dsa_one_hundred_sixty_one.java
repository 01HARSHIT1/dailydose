/**
 * Basic DSA Problems - Binary Tree Maximum Depth
 * Height of binary tree (longest path from root to leaf)
 */
public class basic_dsa_one_hundred_sixty_one {

    // Problem: Given root of binary tree, return its maximum depth (number of nodes on longest path).

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Depth = 1 + max(depth(left), depth(right)). Base: null -> 0.
     * Time O(n), Space O(h)
     */
    public static int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Depth of Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("Depth -> " + maxDepth(root));
    }
}
