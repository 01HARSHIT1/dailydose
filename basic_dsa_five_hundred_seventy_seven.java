/**
 * Basic DSA Problems - One Fundamental Tree Traversal Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_seven {

    // Problem 1: Symmetric Tree
    // Given the root of a binary tree, check whether it is a mirror of itself.
    //
    // A tree is symmetric if the left subtree is a mirror reflection of the right subtree.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Recursive mirror check
     * Time Complexity: O(n)
     * Space Complexity: O(h), h = tree height
     */
    public static Boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isMirror(root.left, root.right);
    }

    private static boolean isMirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null) {
            return false;
        }
        if (a.val != b.val) {
            return false;
        }
        return isMirror(a.left, b.right) && isMirror(a.right, b.left);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Symmetric Tree");
        System.out.println("=".repeat(60));

        // Symmetric tree: [1,2,2,3,4,4,3]
        TreeNode s = new TreeNode(1);
        s.left = new TreeNode(2);
        s.right = new TreeNode(2);
        s.left.left = new TreeNode(3);
        s.left.right = new TreeNode(4);
        s.right.left = new TreeNode(4);
        s.right.right = new TreeNode(3);
        System.out.println("isSymmetric(symmetricTree) -> " + isSymmetric(s));

        // Non-symmetric tree: [1,2,2,null,3,null,3]
        TreeNode n = new TreeNode(1);
        n.left = new TreeNode(2);
        n.right = new TreeNode(2);
        n.left.right = new TreeNode(3);
        n.right.right = new TreeNode(3);
        System.out.println("isSymmetric(nonSymmetricTree) -> " + isSymmetric(n));

        System.out.println("isSymmetric(null) -> " + isSymmetric(null));
    }
}
