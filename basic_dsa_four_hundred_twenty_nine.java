/**
 * Basic DSA Problems - N-ary Tree Level Order Traversal (LeetCode 429)
 * Return node values level by level (BFS)
 */
public class basic_dsa_four_hundred_twenty_nine {

    static class Node {
        int val;
        java.util.List<Node> children;
        Node() { children = new java.util.ArrayList<>(); }
        Node(int v) { val = v; children = new java.util.ArrayList<>(); }
    }

    /**
     * BFS with queue. Process each level, add children for next.
     * Time O(n), Space O(n)
     */
    public static java.util.List<java.util.List<Integer>> levelOrder(Node root) {
        java.util.List<java.util.List<Integer>> ans = new java.util.ArrayList<>();
        if (root == null) return ans;
        java.util.Queue<Node> q = new java.util.LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            java.util.List<Integer> level = new java.util.ArrayList<>();
            for (int i = 0; i < size; i++) {
                Node n = q.poll();
                level.add(n.val);
                for (Node c : n.children) q.offer(c);
            }
            ans.add(level);
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: N-ary Tree Level Order Traversal");
        System.out.println("=".repeat(60));

        Node r = new Node(1);
        r.children.add(new Node(3));
        r.children.add(new Node(2));
        r.children.add(new Node(4));
        r.children.get(0).children.add(new Node(5));
        r.children.get(0).children.add(new Node(6));
        System.out.println("3-ary tree -> " + levelOrder(r));

        Node r2 = new Node(1);
        r2.children.add(new Node(2));
        r2.children.add(new Node(3));
        r2.children.add(new Node(4));
        r2.children.add(new Node(5));
        r2.children.get(1).children.add(new Node(6));
        r2.children.get(1).children.add(new Node(7));
        r2.children.get(3).children.add(new Node(8));
        System.out.println("Another tree -> " + levelOrder(r2));
    }
}
