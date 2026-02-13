/**
 * Basic DSA Problems - Reverse Linked List
 * Reverse a singly linked list iteratively
 */
public class basic_dsa_two_hundred_seventy_nine {

    // Problem: Reverse the linked list and return new head.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; }
    }

    /**
     * Iterative: prev, curr, next. Point curr to prev, advance.
     * Time O(n), Space O(1)
     */
    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Linked List");
        System.out.println("=".repeat(60));

        ListNode h = new ListNode(1);
        h.next = new ListNode(2);
        h.next.next = new ListNode(3);
        h.next.next.next = new ListNode(4);
        h.next.next.next.next = new ListNode(5);

        ListNode r = reverseList(h);
        StringBuilder sb = new StringBuilder();
        while (r != null) {
            sb.append(r.val).append(r.next != null ? "->" : "");
            r = r.next;
        }
        System.out.println("1->2->3->4->5 -> " + sb);
    }
}
