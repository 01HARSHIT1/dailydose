/**
 * Basic DSA Problems - Delete Node in a BST (LeetCode 450)
 * Remove node with given key, preserve BST property. O(h) time.
 */
public class basic_dsa_four_hundred_fifty {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    // Problem: delete key from BST. Cases: 0/1/2 children.

    /**
     * If key found: 0 children->null; 1 child->that child; 2->replace with successor.
     * Time O(h), Space O(h)
     */
    public static TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if (key > root.val) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;
        TreeNode succ = root.right;
        while (succ.left != null) succ = succ.left;
        root.val = succ.val;
        root.right = deleteNode(root.right, succ.val);
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Delete Node in a BST");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(5);
        r.left = new TreeNode(3);
        r.right = new TreeNode(6);
        r.left.left = new TreeNode(2);
        r.left.right = new TreeNode(4);
        r.right.right = new TreeNode(7);
        TreeNode res = deleteNode(r, 3);
        System.out.println("Delete 3 from [5,3,6,2,4,null,7] -> root=" + (res != null ? res.val : "null") + ", left=" + (res != null && res.left != null ? res.left.val : "null"));
    }
}
