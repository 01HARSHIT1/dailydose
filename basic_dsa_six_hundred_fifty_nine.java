/**
 * Basic DSA Problems - One Fundamental Binary Tree DFS Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_nine {

    // Problem 1: Sum Root to Leaf Numbers
    // Each root-to-leaf path reads as a decimal number (no leading zeros in problem). Return the sum.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Pass running value cur; at leaf return cur; else sum children
     * Time Complexity: O(n)
     * Space Complexity: O(h)
     */
    public static int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private static int dfs(TreeNode n, int cur) {
        if (n == null) {
            return 0;
        }
        cur = cur * 10 + n.val;
        if (n.left == null && n.right == null) {
            return cur;
        }
        return dfs(n.left, cur) + dfs(n.right, cur);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Sum Root to Leaf Numbers");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("1,2,3 -> " + sumNumbers(root));

        TreeNode r2 = new TreeNode(4);
        r2.left = new TreeNode(9);
        r2.right = new TreeNode(0);
        r2.left.left = new TreeNode(5);
        r2.left.right = new TreeNode(1);
        System.out.println("495+491+40 -> " + sumNumbers(r2));

        System.out.println("null -> " + sumNumbers(null));
    }
}
