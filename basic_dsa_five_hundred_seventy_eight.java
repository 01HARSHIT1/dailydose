/**
 * Basic DSA Problems - One Fundamental Tree Traversal Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_eight {

    // Problem 1: Binary Tree Inorder Traversal
    // Given the root of a binary tree, return the inorder traversal of its nodes' values.
    //
    // Inorder traversal visits: left -> root -> right.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Iterative inorder traversal using explicit stack
     * Time Complexity: O(n)
     * Space Complexity: O(h), h = tree height
     */
    public static int[] inorderTraversal(TreeNode root) {
        java.util.ArrayList<Integer> order = new java.util.ArrayList<>();
        java.util.ArrayDeque<TreeNode> stack = new java.util.ArrayDeque<>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            current = stack.pop();
            order.add(current.val);
            current = current.right;
        }

        int[] result = new int[order.size()];
        for (int i = 0; i < order.size(); i++) {
            result[i] = order.get(i);
        }
        return result;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Binary Tree Inorder Traversal");
        System.out.println("=".repeat(60));

        // Tree: [1,null,2,3]
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        System.out.println("inorder([1,null,2,3]) -> " + arrayToString(inorderTraversal(root)));

        TreeNode single = new TreeNode(1);
        System.out.println("inorder([1]) -> " + arrayToString(inorderTraversal(single)));

        System.out.println("inorder([]) -> " + arrayToString(inorderTraversal(null)));
    }
}
