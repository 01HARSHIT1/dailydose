/**
 * Basic DSA Problems - Invert Binary Tree
 * Swap left and right children at every node
 */
public class basic_dsa_one_hundred_sixty {

    // Problem: Invert a binary tree (mirror it). Swap left and right of every node.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Recursive: invert left and right subtrees, then swap left/right of root.
     * Time O(n), Space O(h)
     */
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        TreeNode L = invertTree(root.left);
        TreeNode R = invertTree(root.right);
        root.left = R;
        root.right = L;
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Invert Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);

        invertTree(root);
        System.out.println("Tree inverted (4: L=7, R=2; 7: L=9, R=6; 2: L=3, R=1)");
    }
}
