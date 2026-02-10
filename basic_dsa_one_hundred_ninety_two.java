/**
 * Basic DSA Problems - Linked List Cycle
 * Detect if linked list has a cycle (O(1) space)
 */
public class basic_dsa_one_hundred_ninety_two {

    // Problem: Given head, return true if list has a cycle.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * Floyd: slow and fast pointers. If they meet, there is a cycle.
     * Time O(n), Space O(1)
     */
    public static boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Linked List Cycle");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(3);
        a.next = new ListNode(2);
        a.next.next = new ListNode(0);
        a.next.next.next = new ListNode(-4);
        a.next.next.next.next = a.next;
        System.out.println("Has cycle -> " + hasCycle(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        b.next.next = b;
        System.out.println("Has cycle -> " + hasCycle(b));

        ListNode c = new ListNode(1);
        System.out.println("Has cycle -> " + hasCycle(c));
    }
}
