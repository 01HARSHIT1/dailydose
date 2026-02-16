/**
 * Basic DSA Problems - Invert Binary Tree
 * Swap left and right children of every node
 */
public class basic_dsa_three_hundred_thirty {

    // Problem: Root of binary tree. Invert it (swap left and right at every node).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Recursive: swap left/right, recurse on both subtrees.
     * Time O(n), Space O(h) for recursion stack
     */
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        TreeNode t = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(t);
        return root;
    }

    static String treeToString(TreeNode n) {
        if (n == null) return "null";
        return "[" + n.val + "," + treeToString(n.left) + "," + treeToString(n.right) + "]";
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Invert Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode a = new TreeNode(4);
        a.left = new TreeNode(2);
        a.right = new TreeNode(7);
        a.left.left = new TreeNode(1);
        a.left.right = new TreeNode(3);
        a.right.left = new TreeNode(6);
        a.right.right = new TreeNode(9);
        invertTree(a);
        System.out.println("[4,2,7,1,3,6,9] -> " + treeToString(a));

        TreeNode b = new TreeNode(2);
        b.left = new TreeNode(1);
        b.right = new TreeNode(3);
        invertTree(b);
        System.out.println("[2,1,3] -> " + treeToString(b));
    }
}
