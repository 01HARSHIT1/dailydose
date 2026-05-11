/**
 * Basic DSA Problems - One Fundamental Divide and Conquer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_fifty_six {

    // Problem 1: Convert Sorted Array to Binary Search Tree
    // Build a height-balanced BST from ascending distinct integers.

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            val = v;
        }
    }

    /**
     * Middle element as root; left/right halves become subtrees
     * Time Complexity: O(n)
     * Space Complexity: O(log n) stack
     */
    public static TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null) {
            return null;
        }
        return build(nums, 0, nums.length - 1);
    }

    private static TreeNode build(int[] nums, int lo, int hi) {
        if (lo > hi) {
            return null;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = build(nums, lo, mid - 1);
        root.right = build(nums, mid + 1, hi);
        return root;
    }

    private static StringBuilder preorder(TreeNode r, StringBuilder sb) {
        if (r == null) {
            return sb;
        }
        sb.append(r.val).append(',');
        preorder(r.left, sb);
        preorder(r.right, sb);
        return sb;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Sorted Array to BST");
        System.out.println("=".repeat(60));

        int[] a = {-10, -3, 0, 5, 9};
        TreeNode root = sortedArrayToBST(a);
        System.out.println("preorder -> " + preorder(root, new StringBuilder()));

        int[] b = {1, 2, 3, 4};
        System.out.println("len 4 preorder -> " + preorder(sortedArrayToBST(b), new StringBuilder()));

        System.out.println("null input -> " + sortedArrayToBST(null));
    }
}
