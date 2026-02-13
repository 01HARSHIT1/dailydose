/**
 * Basic DSA Problems - Invert Binary Tree
 * Swap left and right subtrees recursively
 */
public class basic_dsa_two_hundred_eighty_two {

    // Problem: Invert the binary tree (swap left and right of every node).
    // Return root.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    /**
     * Recursive: swap left/right, then invert both subtrees.
     * Time O(n), Space O(h)
     */
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        TreeNode tmp = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(tmp);
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Invert Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(4);
        r.left = new TreeNode(2);
        r.right = new TreeNode(7);
        r.left.left = new TreeNode(1);
        r.left.right = new TreeNode(3);
        r.right.left = new TreeNode(6);
        r.right.right = new TreeNode(9);

        invertTree(r);
        System.out.println("4(2(1,3),7(6,9)) inverted -> 4(7(9,6),2(3,1))");
    }
}
