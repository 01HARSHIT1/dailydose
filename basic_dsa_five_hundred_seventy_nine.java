/**
 * Basic DSA Problems - One Fundamental Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_nine {

    // Problem 1: Invert Binary Tree
    // Given the root of a binary tree, invert the tree, and return its root.
    //
    // Example:
    //     4                 4
    //   /   \    ->       /   \
    //  2     7           7     2
    // / \   / \         / \   / \
    //1   3 6   9       9   6 3   1

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Swap children at each node (post-order style recursion)
     * Time Complexity: O(n)
     * Space Complexity: O(h), h = tree height
     */
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }

    private static String preorder(TreeNode node) {
        if (node == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append(node.val);
        if (node.left != null || node.right != null) {
            sb.append("(").append(preorder(node.left)).append(",").append(preorder(node.right)).append(")");
        }
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Invert Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);
        System.out.println("before -> " + preorder(root));
        invertTree(root);
        System.out.println("after  -> " + preorder(root));

        TreeNode single = new TreeNode(1);
        System.out.println("single before -> " + preorder(single));
        invertTree(single);
        System.out.println("single after  -> " + preorder(single));

        System.out.println("null -> " + (invertTree(null) == null));
    }
}
