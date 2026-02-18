/**
 * Basic DSA Problems - House Robber III (LeetCode 337)
 * Max sum of non-adjacent nodes in binary tree (no parent-child together)
 */
public class basic_dsa_three_hundred_thirty_seven {

    // Problem: Binary tree, each node has value. Rob max sum, no two adjacent nodes (parent-child).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Return [rob this, skip this]. DP: rob = val + skip children; skip = max of children sums.
     * Time O(n), Space O(h)
     */
    public static int rob(TreeNode root) {
        int[] r = dfs(root);
        return Math.max(r[0], r[1]);
    }

    private static int[] dfs(TreeNode n) {
        if (n == null) return new int[]{0, 0};
        int[] l = dfs(n.left);
        int[] r = dfs(n.right);
        int rob = n.val + l[1] + r[1];
        int skip = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return new int[]{rob, skip};
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: House Robber III");
        System.out.println("=".repeat(60));

        TreeNode a = new TreeNode(3);
        a.left = new TreeNode(2);
        a.right = new TreeNode(3);
        a.left.right = new TreeNode(3);
        a.right.right = new TreeNode(1);
        System.out.println("[3,2,3,null,3,null,1] -> " + rob(a));

        TreeNode b = new TreeNode(3);
        b.left = new TreeNode(4);
        b.right = new TreeNode(5);
        b.left.left = new TreeNode(1);
        b.left.right = new TreeNode(3);
        b.right.right = new TreeNode(1);
        System.out.println("[3,4,5,1,3,null,1] -> " + rob(b));
    }
}
