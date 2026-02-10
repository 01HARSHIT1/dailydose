/**
 * Basic DSA Problems - Reverse Linked List
 * Reverse a singly linked list iteratively
 */
public class basic_dsa_one_hundred_eighty_seven {

    // Problem: Given head of singly linked list, return head of reversed list.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * Iterative: prev=null, while head: next=head.next, head.next=prev, prev=head, head=next. Return prev.
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

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(3);
        a.next.next.next = new ListNode(4);
        ListNode rev = reverseList(a);
        StringBuilder sb = new StringBuilder();
        while (rev != null) {
            sb.append(rev.val).append(" ");
            rev = rev.next;
        }
        System.out.println("Reversed -> " + sb.toString().trim());
    }
}
