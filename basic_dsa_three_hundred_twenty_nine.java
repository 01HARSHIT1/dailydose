/**
 * Basic DSA Problems - Reverse Linked List
 * Reverse a singly linked list iteratively
 */
public class basic_dsa_three_hundred_twenty_nine {

    // Problem: Head of singly linked list. Return head of reversed list.

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Iterative: prev=null, curr=head. For each node, reverse link, advance prev and curr.
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

    static String listToString(ListNode head) {
        StringBuilder sb = new StringBuilder();
        while (head != null) {
            sb.append(head.val);
            if (head.next != null) sb.append(",");
            head = head.next;
        }
        return "[" + sb + "]";
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Linked List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        System.out.println("[1,2,3,4,5] -> " + listToString(reverseList(a)));

        ListNode b = new ListNode(1, new ListNode(2, null));
        System.out.println("[1,2] -> " + listToString(reverseList(b)));
    }
}
