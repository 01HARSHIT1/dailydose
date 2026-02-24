/**
 * Basic DSA Problems - Serialize and Deserialize N-ary Tree (LeetCode 428)
 * Serialize N-ary tree to string; deserialize back. Stateless.
 */
public class basic_dsa_four_hundred_twenty_eight {

    static class Node {
        int val;
        java.util.List<Node> children;
        Node() { children = new java.util.ArrayList<>(); }
        Node(int v) { val = v; children = new java.util.ArrayList<>(); }
    }

    static final String SEP = ",";
    static final String NULL = "#";

    /**
     * Preorder: val,childrenSize, then each child recursively.
     * Time O(n), Space O(n)
     */
    public static String serialize(Node root) {
        if (root == null) return "";
        StringBuilder sb = new StringBuilder();
        build(root, sb);
        return sb.toString();
    }

    private static void build(Node node, StringBuilder sb) {
        if (node == null) {
            sb.append(NULL).append(SEP).append(0).append(SEP);
        } else {
            sb.append(node.val).append(SEP).append(node.children.size()).append(SEP);
            for (Node c : node.children) build(c, sb);
        }
    }

    public static Node deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        java.util.Queue<String> q = new java.util.LinkedList<>(java.util.Arrays.asList(data.split(SEP)));
        return parse(q);
    }

    private static Node parse(java.util.Queue<String> q) {
        String v = q.poll();
        if (v.equals(NULL)) return null;
        Node node = new Node(Integer.parseInt(v));
        int sz = Integer.parseInt(q.poll());
        for (int i = 0; i < sz; i++) node.children.add(parse(q));
        return node;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Serialize and Deserialize N-ary Tree");
        System.out.println("=".repeat(60));

        Node r1 = new Node(1);
        r1.children.add(new Node(3));
        r1.children.add(new Node(2));
        r1.children.add(new Node(4));
        r1.children.get(0).children.add(new Node(5));
        r1.children.get(0).children.add(new Node(6));
        String s1 = serialize(r1);
        Node d1 = deserialize(s1);
        System.out.println("Tree [1,[3,[5,6],2,4]] -> " + serialize(d1));
        System.out.println("Round-trip OK: " + s1.equals(serialize(d1)));
    }
}
