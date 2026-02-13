/**
 * Basic DSA Problems - Remove Linked List Elements
 * Remove all nodes with given value
 */
public class basic_dsa_two_hundred_seventy_six {

    // Problem: Remove all nodes with value val from linked list. Return head.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; }
    }

    /**
     * Dummy head to simplify. Prev.next skips nodes with val.
     * Time O(n), Space O(1)
     */
    public static ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        while (prev.next != null) {
            if (prev.next.val == val) prev.next = prev.next.next;
            else prev = prev.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Linked List Elements");
        System.out.println("=".repeat(60));

        ListNode h = new ListNode(1);
        h.next = new ListNode(2);
        h.next.next = new ListNode(6);
        h.next.next.next = new ListNode(3);
        h.next.next.next.next = new ListNode(4);
        h.next.next.next.next.next = new ListNode(5);
        h.next.next.next.next.next.next = new ListNode(6);

        ListNode r = removeElements(h, 6);
        StringBuilder sb = new StringBuilder();
        while (r != null) {
            sb.append(r.val).append(r.next != null ? "->" : "");
            r = r.next;
        }
        System.out.println("1->2->6->3->4->5->6, val=6 -> " + sb);
    }
}
