/**
 * Basic DSA Problems - Diameter of Binary Tree
 * Longest path between any two nodes (may not pass through root)
 */
public class basic_dsa_one_hundred_sixty_two {

    // Problem: Diameter = longest path between any two nodes. Return its length (edge count).

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    static int diameter;

    /**
     * At each node, diameter through node = 1 + leftDepth + rightDepth (edges). Track max.
     * Time O(n), Space O(h)
     */
    public static int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        height(root);
        return diameter;
    }

    static int height(TreeNode node) {
        if (node == null) return -1;
        int L = height(node.left) + 1;
        int R = height(node.right) + 1;
        diameter = Math.max(diameter, L + R);
        return Math.max(L, R);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Diameter of Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println("Diameter -> " + diameterOfBinaryTree(root));
    }
}
