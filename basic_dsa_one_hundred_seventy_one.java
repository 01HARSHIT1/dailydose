/**
 * Basic DSA Problems - Binary Tree Maximum Path Sum
 * Max sum of any path (node-to-node, not necessarily through root)
 */
public class basic_dsa_one_hundred_seventy_one {

    // Problem: Return max path sum. Path = any sequence of connected nodes (each node at most once).

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    static int maxSum;

    /**
     * At each node: max path through node = node + max(0, leftGain) + max(0, rightGain).
     * Return to parent: node + max(0, leftGain, rightGain) (single branch for extending path).
     * Time O(n), Space O(h)
     */
    public static int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        gain(root);
        return maxSum;
    }

    static int gain(TreeNode node) {
        if (node == null) return 0;
        int L = Math.max(0, gain(node.left));
        int R = Math.max(0, gain(node.right));
        maxSum = Math.max(maxSum, node.val + L + R);
        return node.val + Math.max(L, R);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Tree Maximum Path Sum");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("Max path sum -> " + maxPathSum(root));
    }
}
