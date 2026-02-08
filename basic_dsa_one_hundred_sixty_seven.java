/**
 * Basic DSA Problems - Binary Tree Level Order Traversal
 * Return values level by level (BFS)
 */
import java.util.*;

public class basic_dsa_one_hundred_sixty_seven {

    // Problem: Given root, return level-order traversal as list of lists (each level one list).

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * BFS with queue; for each level, poll all current size nodes and add their vals, then add children.
     * Time O(n), Space O(n)
     */
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<>();
        if (root == null) return out;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                level.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            out.add(level);
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Tree Level Order Traversal");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("Level order -> " + levelOrder(root));
    }
}
