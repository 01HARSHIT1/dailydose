/**
 * Basic DSA Problems - Binary Tree Level Order Traversal
 * Return level-by-level traversal as list of lists
 */
public class basic_dsa_three_hundred_thirty_three {

    // Problem: Root of binary tree. Return level order (BFS) as list of lists.

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * BFS with queue, collect nodes level by level.
     * Time O(n), Space O(n)
     */
    public static java.util.List<java.util.List<Integer>> levelOrder(TreeNode root) {
        java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
        if (root == null) return out;
        java.util.Queue<TreeNode> q = new java.util.LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            java.util.List<Integer> level = new java.util.ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode n = q.poll();
                level.add(n.val);
                if (n.left != null) q.offer(n.left);
                if (n.right != null) q.offer(n.right);
            }
            out.add(level);
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Tree Level Order Traversal");
        System.out.println("=".repeat(60));

        TreeNode a = new TreeNode(3);
        a.left = new TreeNode(9);
        a.right = new TreeNode(20);
        a.right.left = new TreeNode(15);
        a.right.right = new TreeNode(7);
        System.out.println("[3,9,20,null,null,15,7] -> " + levelOrder(a));

        TreeNode b = new TreeNode(1);
        System.out.println("[1] -> " + levelOrder(b));
    }
}
