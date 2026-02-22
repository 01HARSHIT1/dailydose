/**
 * Basic DSA Problems - Sum of Left Leaves (LeetCode 404)
 * Sum values of left-child leaves only
 */
public class basic_dsa_four_hundred_four {

    // Problem: Sum of left leaves (leaf = no children, left child of parent).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * DFS: add val when node is leaf and is left child.
     * Time O(n), Space O(h)
     */
    public static int sumOfLeftLeaves(TreeNode root) {
        return dfs(root, false);
    }

    private static int dfs(TreeNode n, boolean isLeft) {
        if (n == null) return 0;
        if (n.left == null && n.right == null) return isLeft ? n.val : 0;
        return dfs(n.left, true) + dfs(n.right, false);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sum of Left Leaves");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println("[3,9,20,null,null,15,7] -> " + sumOfLeftLeaves(root));
    }
}
