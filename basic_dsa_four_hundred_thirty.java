/**
 * Basic DSA Problems - Flatten a Multilevel Doubly Linked List (LeetCode 430)
 * Flatten: when node has child, insert child list between node and node.next
 */
public class basic_dsa_four_hundred_thirty {

    static class Node {
        int val;
        Node prev, next, child;
        Node(int v) { val = v; }
    }

    /**
     * Iterative: if node has child, splice child list in, find tail, link to next.
     * Time O(n), Space O(1)
     */
    public static Node flatten(Node head) {
        for (Node curr = head; curr != null; curr = curr.next) {
            if (curr.child != null) {
                Node next = curr.next;
                curr.next = curr.child;
                curr.child.prev = curr;
                curr.child = null;
                Node tail = curr.next;
                while (tail.next != null) tail = tail.next;
                tail.next = next;
                if (next != null) next.prev = tail;
            }
        }
        return head;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Flatten a Multilevel Doubly Linked List");
        System.out.println("=".repeat(60));

        Node n1 = new Node(1), n2 = new Node(2), n3 = new Node(3), n4 = new Node(4);
        n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2; n3.next = n4; n4.prev = n3;
        Node n7 = new Node(7), n8 = new Node(8), n9 = new Node(9);
        n7.next = n8; n8.prev = n7; n8.next = n9; n9.prev = n8;
        n3.child = n7;
        Node n11 = new Node(11), n12 = new Node(12);
        n11.next = n12; n12.prev = n11;
        n8.child = n11;

        Node h = flatten(n1);
        System.out.print("1-2-3(7-8(11-12)-9)-4 -> ");
        while (h != null) {
            System.out.print(h.val + (h.next != null ? "-" : ""));
            h = h.next;
        }
        System.out.println();
    }
}
