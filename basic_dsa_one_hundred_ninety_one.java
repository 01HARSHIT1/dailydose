/**
 * Basic DSA Problems - Copy List with Random Pointer
 * Deep copy a linked list where each node has next and random pointer
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_one_hundred_ninety_one {

    // Problem: Each node has next and random. Return deep copy of the list.

    public static class Node {
        int val;
        Node next, random;
        Node(int val) { this.val = val; }
    }

    /**
     * Map old -> new. First pass create copies; second pass set next and random.
     * Time O(n), Space O(n)
     */
    public static Node copyRandomList(Node head) {
        if (head == null) return null;
        Map<Node, Node> map = new HashMap<>();
        Node cur = head;
        while (cur != null) {
            map.put(cur, new Node(cur.val));
            cur = cur.next;
        }
        cur = head;
        while (cur != null) {
            Node copy = map.get(cur);
            copy.next = map.get(cur.next);
            copy.random = map.get(cur.random);
            cur = cur.next;
        }
        return map.get(head);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Copy List with Random Pointer");
        System.out.println("=".repeat(60));

        Node a = new Node(7);
        Node b = new Node(13);
        Node c = new Node(11);
        Node d = new Node(10);
        Node e = new Node(1);
        a.next = b; b.next = c; c.next = d; d.next = e;
        a.random = null; b.random = a; c.random = e; d.random = c; e.random = a;

        Node copy = copyRandomList(a);
        System.out.println("Copy head val -> " + (copy != null ? copy.val : "null"));
    }
}
