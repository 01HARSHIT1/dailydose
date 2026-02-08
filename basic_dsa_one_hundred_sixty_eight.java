/**
 * Basic DSA Problems - Validate Binary Search Tree
 * Check if tree is a valid BST (left < root < right, recursively)
 */
public class basic_dsa_one_hundred_sixty_eight {

    // Problem: Given root, return true if it is a valid BST.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Pass (min, max) allowed range; root must be in (min,max), left in (min, root), right in (root, max).
     * Time O(n), Space O(h)
     */
    public static boolean isValidBST(TreeNode root) {
        return valid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    static boolean valid(TreeNode node, long min, long max) {
        if (node == null) return true;
        if (node.val <= min || node.val >= max) return false;
        return valid(node.left, min, node.val) && valid(node.right, node.val, max);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Validate BST");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        System.out.println("Valid BST -> " + isValidBST(root));
    }
}
