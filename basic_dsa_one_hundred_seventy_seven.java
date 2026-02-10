/**
 * Basic DSA Problems - Clone Graph
 * Deep copy a connected undirected graph (each node has list of neighbors)
 */
import java.util.*;

public class basic_dsa_one_hundred_seventy_seven {

    // Problem: Given node of a graph, return a deep copy (clone) of the graph.

    public static class Node {
        public int val;
        public List<Node> neighbors;
        public Node(int val) {
            this.val = val;
            neighbors = new ArrayList<>();
        }
    }

    /**
     * BFS/DFS with map: original -> clone. For each node, create clone and copy neighbors.
     * Time O(V+E), Space O(V)
     */
    public static Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> map = new HashMap<>();
        map.put(node, new Node(node.val));
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        while (!q.isEmpty()) {
            Node cur = q.poll();
            Node clone = map.get(cur);
            for (Node nb : cur.neighbors) {
                if (!map.containsKey(nb)) {
                    map.put(nb, new Node(nb.val));
                    q.offer(nb);
                }
                clone.neighbors.add(map.get(nb));
            }
        }
        return map.get(node);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Clone Graph");
        System.out.println("=".repeat(60));

        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        a.neighbors.add(b);
        a.neighbors.add(d);
        b.neighbors.add(a);
        b.neighbors.add(c);
        c.neighbors.add(b);
        c.neighbors.add(d);
        d.neighbors.add(a);
        d.neighbors.add(c);

        Node clone = cloneGraph(a);
        System.out.println("Clone root val -> " + (clone != null ? clone.val : "null"));
    }
}
