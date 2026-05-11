/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_one {

    // Problem 1: Same Tree
    // Two binary trees are the same if structure and every node value match.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Recursive match: both null, or same val and same left/right subtrees
     * Time Complexity: O(min(n, m))
     * Space Complexity: O(min(h1, h2)) stack
     */
    public static boolean isSameTree(TreeNode p, TreeNode q) {
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

    private static TreeNode buildSample() {
        TreeNode r = new TreeNode(1);
        r.left = new TreeNode(2);
        r.right = new TreeNode(3);
        return r;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Same Tree");
        System.out.println("=".repeat(60));

        TreeNode a = buildSample();
        TreeNode b = buildSample();
        System.out.println("two equal -> " + isSameTree(a, b));

        TreeNode c = new TreeNode(1);
        c.left = new TreeNode(2);
        TreeNode d = new TreeNode(1);
        d.right = new TreeNode(2);
        System.out.println("different shape -> " + isSameTree(c, d));

        System.out.println("null,null -> " + isSameTree(null, null));
        System.out.println("null,node -> " + isSameTree(null, a));
    }
}
