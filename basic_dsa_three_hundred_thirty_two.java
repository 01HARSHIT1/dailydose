/**
 * Basic DSA Problems - Maximum Depth of Binary Tree
 * Return the maximum depth (height) of a binary tree
 */
public class basic_dsa_three_hundred_thirty_two {

    // Problem: Root of binary tree. Return its maximum depth (number of nodes from root to farthest leaf).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Recursive: 1 + max(depth(left), depth(right)).
     * Time O(n), Space O(h)
     */
    public static int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum Depth of Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode a = new TreeNode(3);
        a.left = new TreeNode(9);
        a.right = new TreeNode(20);
        a.right.left = new TreeNode(15);
        a.right.right = new TreeNode(7);
        System.out.println("[3,9,20,null,null,15,7] -> " + maxDepth(a));

        TreeNode b = new TreeNode(1);
        b.right = new TreeNode(2);
        System.out.println("[1,null,2] -> " + maxDepth(b));
    }
}
