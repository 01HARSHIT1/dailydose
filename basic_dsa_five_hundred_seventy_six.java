/**
 * Basic DSA Problems - One Fundamental Graph/Tree Traversal Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_six {

    // Problem 1: Same Tree
    // Given the roots of two binary trees p and q, return true if they are the same tree.
    // Two trees are the same if they are structurally identical and nodes have the same values.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Recursive parallel traversal comparison
     * Time Complexity: O(n)
     * Space Complexity: O(h), h = tree height
     */
    public static Boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Same Tree");
        System.out.println("=".repeat(60));

        // Tree A: [1,2,3]
        TreeNode a = new TreeNode(1);
        a.left = new TreeNode(2);
        a.right = new TreeNode(3);

        // Tree B: [1,2,3]
        TreeNode b = new TreeNode(1);
        b.left = new TreeNode(2);
        b.right = new TreeNode(3);

        // Tree C: [1,2,4]
        TreeNode c = new TreeNode(1);
        c.left = new TreeNode(2);
        c.right = new TreeNode(4);

        System.out.println("isSameTree(A, B) -> " + isSameTree(a, b)); // true
        System.out.println("isSameTree(A, C) -> " + isSameTree(a, c)); // false
        System.out.println("isSameTree(null, null) -> " + isSameTree(null, null)); // true
        System.out.println("isSameTree(A, null) -> " + isSameTree(a, null)); // false
    }
}
