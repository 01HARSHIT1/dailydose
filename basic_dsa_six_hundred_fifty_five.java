import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

/**
 * Basic DSA Problems - One Fundamental BFS Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_five {

    // Problem 1: Binary Tree Level Order Traversal
    // Return values grouped by depth, top to bottom.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Queue BFS: snapshot queue size each level
     * Time Complexity: O(n)
     * Space Complexity: O(w) where w is max width
     */
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>(size);
            for (int i = 0; i < size; i++) {
                TreeNode n = q.poll();
                level.add(n.val);
                if (n.left != null) {
                    q.add(n.left);
                }
                if (n.right != null) {
                    q.add(n.right);
                }
            }
            result.add(level);
        }

        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Binary Tree Level Order Traversal");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("classic -> " + levelOrder(root));
        System.out.println("single -> " + levelOrder(new TreeNode(1)));
        System.out.println("null -> " + levelOrder(null));
    }
}
