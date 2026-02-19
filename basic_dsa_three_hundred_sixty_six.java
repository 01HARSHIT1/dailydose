/**
 * Basic DSA Problems - Find Leaves of Binary Tree (LeetCode 366)
 * Collect leaves by layer: all leaves first, then remove, repeat
 */
public class basic_dsa_three_hundred_sixty_six {

    // Problem: Collect leaves layer by layer (leaves first, then next level, etc).

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Height from bottom: leaves=0, their parents=1, etc. Group by height.
     * Time O(n), Space O(h)
     */
    public static java.util.List<java.util.List<Integer>> findLeaves(TreeNode root) {
        java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
        height(root, out);
        return out;
    }

    private static int height(TreeNode n, java.util.List<java.util.List<Integer>> out) {
        if (n == null) return -1;
        int h = 1 + Math.max(height(n.left, out), height(n.right, out));
        if (h == out.size()) out.add(new java.util.ArrayList<>());
        out.get(h).add(n.val);
        return h;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find Leaves of Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        System.out.println("[1,2,3,4,5] -> " + findLeaves(root));
    }
}
