/**
 * Basic DSA Problems - Kth Smallest Element in a BST
 * Find kth smallest value in BST (1-indexed)
 */
public class basic_dsa_one_hundred_sixty_nine {

    // Problem: Given BST root and integer k, return the kth smallest value (1-indexed).

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    static int count, result;

    /**
     * Inorder traversal visits nodes in sorted order; stop at kth node.
     * Time O(k) average, O(n) worst. Space O(h)
     */
    public static int kthSmallest(TreeNode root, int k) {
        count = 0;
        result = 0;
        inorder(root, k);
        return result;
    }

    static void inorder(TreeNode node, int k) {
        if (node == null) return;
        inorder(node.left, k);
        if (++count == k) {
            result = node.val;
            return;
        }
        inorder(node.right, k);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Kth Smallest in BST");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.left.right = new TreeNode(2);

        System.out.println("k=1 -> " + kthSmallest(root, 1));
        System.out.println("k=2 -> " + kthSmallest(root, 2));
    }
}
