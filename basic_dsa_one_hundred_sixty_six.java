/**
 * Basic DSA Problems - Lowest Common Ancestor of a Binary Search Tree
 * Find LCA of two nodes in a BST
 */
public class basic_dsa_one_hundred_sixty_six {

    // Problem: Given BST root and two nodes p, q. Return their lowest common ancestor.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * If both p,q < root, LCA is in left; if both > root, LCA is in right; else root is LCA.
     * Time O(h), Space O(h)
     */
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (p.val < root.val && q.val < root.val) return lowestCommonAncestor(root.left, p, q);
        if (p.val > root.val && q.val > root.val) return lowestCommonAncestor(root.right, p, q);
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: LCA of BST");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(2);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(9);

        TreeNode p = root.left;
        TreeNode q = root.left.right;
        TreeNode lca = lowestCommonAncestor(root, p, q);
        System.out.println("LCA(2, 4) -> " + lca.val);
    }
}
