/**
 * Basic DSA Problems - One Fundamental Binary Tree Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_four {

    // Problem 1: Path Sum
    // Exists root-to-leaf path whose node values sum to targetSum?

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * DFS: subtract value going down; leaf checks remainder == 0
     * Time Complexity: O(n)
     * Space Complexity: O(h)
     */
    public static boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        if (root.left == null && root.right == null) {
            return root.val == targetSum;
        }
        int rest = targetSum - root.val;
        return hasPathSum(root.left, rest) || hasPathSum(root.right, rest);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Path Sum");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(4);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(11);
        root.left.left.left = new TreeNode(7);
        root.left.left.right = new TreeNode(2);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(4);

        System.out.println("target 22 -> " + hasPathSum(root, 22));
        System.out.println("target 100 -> " + hasPathSum(root, 100));
        System.out.println("null -> " + hasPathSum(null, 0));
    }
}
