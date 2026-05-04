/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_four {

    // Problem 1: Search in a Binary Search Tree
    // Given the root node of a BST and a value val, return the subtree rooted
    // with the node that has value val. If such node does not exist, return null.
    //
    // Example:
    // BST: [4,2,7,1,3], val = 2 -> subtree rooted at 2

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * Iterative BST search
     * Time Complexity: O(h), h = tree height
     * Space Complexity: O(1)
     */
    public static TreeNode searchBST(TreeNode root, int val) {
        TreeNode current = root;
        while (current != null) {
            if (current.val == val) {
                return current;
            }
            if (val < current.val) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return null;
    }

    private static void printPreorder(TreeNode node) {
        if (node == null) {
            System.out.print("null");
            return;
        }
        System.out.print(node.val + " ");
        printPreorder(node.left);
        System.out.print(" ");
        printPreorder(node.right);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Search in a Binary Search Tree");
        System.out.println("=".repeat(60));

        // Build BST:      4
        //               /   \
        //              2     7
        //             / \
        //            1   3
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        TreeNode found = searchBST(root, 2);
        System.out.print("searchBST(root, 2) preorder -> ");
        printPreorder(found);
        System.out.println();

        TreeNode missing = searchBST(root, 5);
        System.out.print("searchBST(root, 5) preorder -> ");
        printPreorder(missing);
        System.out.println();
    }
}
