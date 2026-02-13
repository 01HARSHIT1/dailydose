/**
 * Basic DSA Problems - Binary Tree Paths
 * Return all root-to-leaf paths in a binary tree
 */
import java.util.ArrayList;
import java.util.List;

public class basic_dsa_two_hundred_fifty_eight {

    // Problem: Given binary tree root, return all root-to-leaf paths. Format: "1->2->5".

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    /**
     * DFS: build path string, add to list when at leaf.
     * Time O(n), Space O(h) recursion
     */
    public static List<String> binaryTreePaths(TreeNode root) {
        List<String> out = new ArrayList<>();
        dfs(root, "", out);
        return out;
    }

    static void dfs(TreeNode node, String path, List<String> out) {
        if (node == null) return;
        String p = path.isEmpty() ? String.valueOf(node.val) : path + "->" + node.val;
        if (node.left == null && node.right == null) {
            out.add(p);
            return;
        }
        dfs(node.left, p, out);
        dfs(node.right, p, out);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Tree Paths");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(1);
        r.left = new TreeNode(2);
        r.right = new TreeNode(3);
        r.left.right = new TreeNode(5);
        System.out.println("  1\n / \\\n2   3\n \\\n  5 -> " + binaryTreePaths(r));

        TreeNode r2 = new TreeNode(1);
        System.out.println("1 -> " + binaryTreePaths(r2));
    }
}
