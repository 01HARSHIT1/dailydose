/**
 * Basic DSA Problems - Construct Binary Tree from Preorder and Inorder
 * Build tree given preorder and inorder traversal arrays
 */
public class basic_dsa_one_hundred_seventy {

    // Problem: Given preorder and inorder of a binary tree (no duplicates), construct and return root.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Preorder[0] is root. Find root in inorder; left of it is left subtree, right is right subtree.
     * Recurse with correct index ranges. Time O(n), Space O(n) for map + O(h) recursion
     */
    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        java.util.Map<Integer, Integer> inIdx = new java.util.HashMap<>();
        for (int i = 0; i < inorder.length; i++) inIdx.put(inorder[i], i);
        return build(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, inIdx);
    }

    static TreeNode build(int[] pre, int pL, int pR, int[] in, int iL, int iR, java.util.Map<Integer, Integer> inIdx) {
        if (pL > pR) return null;
        TreeNode root = new TreeNode(pre[pL]);
        int m = inIdx.get(pre[pL]);
        int leftSize = m - iL;
        root.left = build(pre, pL + 1, pL + leftSize, in, iL, m - 1, inIdx);
        root.right = build(pre, pL + leftSize + 1, pR, in, m + 1, iR, inIdx);
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Build Tree from Preorder and Inorder");
        System.out.println("=".repeat(60));

        int[] pre = {3, 9, 20, 15, 7};
        int[] in = {9, 3, 15, 20, 7};
        TreeNode root = buildTree(pre, in);
        System.out.println("Root val -> " + (root != null ? root.val : "null"));
    }
}
