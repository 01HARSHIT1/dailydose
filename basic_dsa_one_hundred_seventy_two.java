/**
 * Basic DSA Problems - Serialize and Deserialize Binary Tree
 * Encode tree to string and decode back to tree
 */
public class basic_dsa_one_hundred_seventy_two {

    // Problem: Design serialization: tree -> string, and deserialization: string -> tree.

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    /**
     * Preorder with "N" for null. Decode by consuming tokens and building preorder.
     */
    public static String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        ser(root, sb);
        return sb.toString();
    }

    static void ser(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("N,");
            return;
        }
        sb.append(node.val).append(",");
        ser(node.left, sb);
        ser(node.right, sb);
    }

    static int idx;
    static String[] tokens;

    public static TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        tokens = data.split(",");
        idx = 0;
        return des();
    }

    static TreeNode des() {
        if (idx >= tokens.length || tokens[idx].equals("N")) {
            idx++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(tokens[idx++]));
        node.left = des();
        node.right = des();
        return node;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Serialize and Deserialize Binary Tree");
        System.out.println("=".repeat(60));

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(5);
        String s = serialize(root);
        System.out.println("Serialized -> " + s);
        TreeNode back = deserialize(s);
        System.out.println("Deserialized root val -> " + (back != null ? back.val : "null"));
    }
}
