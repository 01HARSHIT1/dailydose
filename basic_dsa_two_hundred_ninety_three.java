/**
 * Basic DSA Problems - Convert Sorted Array to Binary Search Tree
 * Build height-balanced BST from sorted array
 */
public class basic_dsa_two_hundred_ninety_three {

    // Problem: Sorted array. Convert to height-balanced BST.
    // Pick middle as root, recurse left and right.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    /**
     * Recursive: mid = root, left half -> left subtree, right half -> right subtree.
     * Time O(n), Space O(log n)
     */
    public static TreeNode sortedArrayToBST(int[] nums) {
        return build(nums, 0, nums.length - 1);
    }

    static TreeNode build(int[] nums, int lo, int hi) {
        if (lo > hi) return null;
        int mid = lo + (hi - lo) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = build(nums, lo, mid - 1);
        node.right = build(nums, mid + 1, hi);
        return node;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Convert Sorted Array to BST");
        System.out.println("=".repeat(60));

        TreeNode r = sortedArrayToBST(new int[]{-10, -3, 0, 5, 9});
        System.out.println("[-10,-3,0,5,9] -> height-balanced BST built");
    }
}
