/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_two {

    // Problem 1: Invert Binary Tree
    // Swap every node's left and right subtrees (mirror the tree).

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Post-order style: invert children then swap pointers
     * Time Complexity: O(n)
     * Space Complexity: O(h) stack
     */
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode leftInv = invertTree(root.left);
        TreeNode rightInv = invertTree(root.right);
        root.left = rightInv;
        root.right = leftInv;
        return root;
    }

    private static String preorder(TreeNode r) {
        if (r == null) {
            return "#";
        }
        return r.val + "," + preorder(r.left) + "," + preorder(r.right);
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

        System.out.println("null -> " + invertTree(null));
    }
}
