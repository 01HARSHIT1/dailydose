/**
 * Basic DSA Problems - All O`one Data Structure (LeetCode 432)
 * inc/dec/getMaxKey/getMinKey in O(1). Doubly linked list of count buckets.
 */
public class basic_dsa_four_hundred_thirty_two {

    static class Node {
        Node prev, next;
        int cnt;
        java.util.Set<String> keys = new java.util.HashSet<>();
        Node() { }
        Node(String key, int c) { cnt = c; keys.add(key); }
        Node insert(Node n) {
            n.prev = this; n.next = this.next;
            n.prev.next = n; n.next.prev = n;
            return n;
        }
        void remove() { prev.next = next; next.prev = prev; }
    }

    static class AllOne {
        Node root = new Node();
        java.util.Map<String, Node> nodes = new java.util.HashMap<>();

        AllOne() { root.next = root; root.prev = root; }

        void inc(String key) {
            if (!nodes.containsKey(key)) {
                if (root.next == root || root.next.cnt > 1)
                    nodes.put(key, root.insert(new Node(key, 1)));
                else {
                    root.next.keys.add(key);
                    nodes.put(key, root.next);
                }
            } else {
                Node curr = nodes.get(key);
                Node next = curr.next;
                if (next == root || next.cnt > curr.cnt + 1)
                    nodes.put(key, curr.insert(new Node(key, curr.cnt + 1)));
                else {
                    next.keys.add(key);
                    nodes.put(key, next);
                }
                curr.keys.remove(key);
                if (curr.keys.isEmpty()) curr.remove();
            }
        }

        void dec(String key) {
            Node curr = nodes.get(key);
            if (curr.cnt == 1) nodes.remove(key);
            else {
                Node prev = curr.prev;
                if (prev == root || prev.cnt < curr.cnt - 1)
                    nodes.put(key, prev.insert(new Node(key, curr.cnt - 1)));
                else {
                    prev.keys.add(key);
                    nodes.put(key, prev);
                }
            }
            curr.keys.remove(key);
            if (curr.keys.isEmpty()) curr.remove();
        }

        String getMaxKey() { return root.prev == root ? "" : root.prev.keys.iterator().next(); }
        String getMinKey() { return root.next == root ? "" : root.next.keys.iterator().next(); }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: All O`one Data Structure");
        System.out.println("=".repeat(60));

        AllOne a = new AllOne();
        a.inc("hello"); a.inc("hello");
        System.out.println("inc hello x2 -> getMax=" + a.getMaxKey() + " getMin=" + a.getMinKey());
        a.inc("leet");
        System.out.println("inc leet -> getMax=" + a.getMaxKey() + " getMin=" + a.getMinKey());
    }
}
