/**
 * Basic DSA Problems - Lowest Common Ancestor of a Binary Search Tree
 * Find LCA of two nodes in BST
 */
public class basic_dsa_two_hundred_eighty_five {

    // Problem: Given BST and two nodes p, q. Return their lowest common ancestor.
    // LCA: deepest node with both p and q as descendants.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    /**
     * BST: if both p,q < root, go left. If both > root, go right. Else root is LCA.
     * Time O(h), Space O(1)
     */
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) root = root.left;
            else if (p.val > root.val && q.val > root.val) root = root.right;
            else return root;
        }
        return null;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Lowest Common Ancestor of BST");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(6);
        r.left = new TreeNode(2);
        r.right = new TreeNode(8);
        r.left.left = new TreeNode(0);
        r.left.right = new TreeNode(4);
        r.right.left = new TreeNode(7);
        r.right.right = new TreeNode(9);

        TreeNode p = r.left, q = r.left.right;
        System.out.println("p=2, q=4 -> LCA=" + lowestCommonAncestor(r, p, q).val);
    }
}
