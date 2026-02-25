/**
 * Basic DSA Problems - Serialize and Deserialize BST (LeetCode 449)
 * Preorder encoding. Deserialize using BST bounds (mi, mx).
 */
public class basic_dsa_four_hundred_forty_nine {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    // Problem: serialize BST to string, deserialize back. Compact, stateless.

    /**
     * Preorder: root, left, right. No null markers needed for BST.
     * Time O(n), Space O(n)
     */
    public static String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        return sb.length() > 0 ? sb.substring(0, sb.length() - 1) : "";
    }

    private static void preorder(TreeNode node, StringBuilder sb) {
        if (node == null) return;
        sb.append(node.val).append(",");
        preorder(node.left, sb);
        preorder(node.right, sb);
    }

    public static TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        String[] parts = data.split(",");
        int[] idx = {0};
        return build(parts, idx, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private static TreeNode build(String[] arr, int[] idx, int mi, int mx) {
        if (idx[0] >= arr.length) return null;
        int x = Integer.parseInt(arr[idx[0]]);
        if (x < mi || x > mx) return null;
        TreeNode root = new TreeNode(x);
        idx[0]++;
        root.left = build(arr, idx, mi, x);
        root.right = build(arr, idx, x, mx);
        return root;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Serialize and Deserialize BST");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(2);
        r.left = new TreeNode(1);
        r.right = new TreeNode(3);
        String s = serialize(r);
        TreeNode back = deserialize(s);
        System.out.println("[2,1,3] -> \"" + s + "\" -> round-trip OK: " + (back.val == 2 && back.left.val == 1 && back.right.val == 3));
    }
}
