/**
 * Basic DSA Problems - Remove Nth Node From End of List
 * Remove the nth node from the end of a linked list (one pass)
 */
public class basic_dsa_one_hundred_eighty_nine {

    // Problem: Given head and n, remove the nth node from the end. Return head.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * Two pointers: advance first by n+1 steps, then move both until first is null; second.next is to remove.
     * Time O(L), Space O(1)
     */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy, slow = dummy;
        for (int i = 0; i <= n; i++) fast = fast.next;
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Nth Node From End of List");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        ListNode result = removeNthFromEnd(head, 2);
        StringBuilder sb = new StringBuilder();
        while (result != null) {
            sb.append(result.val).append(" ");
            result = result.next;
        }
        System.out.println("After removing 2nd from end -> " + sb.toString().trim());
    }
}
