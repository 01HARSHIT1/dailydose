/**
 * Basic DSA Problems - Encode N-ary Tree to Binary Tree (LeetCode 431)
 * Left-child right-sibling: binary left=first child, binary right=next sibling
 */
public class basic_dsa_four_hundred_thirty_one {

    static class Node {
        int val;
        java.util.List<Node> children;
        Node() { children = new java.util.ArrayList<>(); }
        Node(int v) { val = v; children = new java.util.ArrayList<>(); }
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    /**
     * Encode: left=first child, chain siblings via right pointers.
     * Time O(n), Space O(h)
     */
    public static TreeNode encode(Node root) {
        if (root == null) return null;
        TreeNode t = new TreeNode(root.val);
        if (!root.children.isEmpty()) {
            t.left = encode(root.children.get(0));
            TreeNode curr = t.left;
            for (int i = 1; i < root.children.size(); i++) {
                curr.right = encode(root.children.get(i));
                curr = curr.right;
            }
        }
        return t;
    }

    /**
     * Decode: children = chain of left->right->right...
     * Time O(n), Space O(h)
     */
    public static Node decode(TreeNode root) {
        if (root == null) return null;
        Node n = new Node(root.val);
        TreeNode child = root.left;
        while (child != null) {
            n.children.add(decode(child));
            child = child.right;
        }
        return n;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Encode N-ary Tree to Binary Tree");
        System.out.println("=".repeat(60));

        Node n = new Node(1);
        n.children.add(new Node(3));
        n.children.add(new Node(2));
        n.children.add(new Node(4));
        n.children.get(0).children.add(new Node(5));
        n.children.get(0).children.add(new Node(6));
        TreeNode bin = encode(n);
        Node back = decode(bin);
        System.out.println("Encode/decode round-trip: root=" + back.val + ", children=" + back.children.size());
    }
}
