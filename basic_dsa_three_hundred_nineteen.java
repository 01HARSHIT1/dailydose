/**
 * Basic DSA Problems - Remove Nth Node From End of List
 * Remove the nth node from the end of a linked list
 */
public class basic_dsa_three_hundred_nineteen {

    // Problem: Head of linked list and n. Remove the nth node from the end. Return head.

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Fast pointer advances n+1 steps; then both move until fast is null. Slow.next is nth from end.
     * Time O(n), Space O(1)
     */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        for (int i = 0; i <= n; i++) fast = fast.next;
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
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
        System.out.println("Problem: Remove Nth Node From End of List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        System.out.println("[1,2,3,4,5], n=2 -> " + listToString(removeNthFromEnd(a, 2)));

        ListNode b = new ListNode(1, null);
        System.out.println("[1], n=1 -> " + listToString(removeNthFromEnd(b, 1)));
    }
}
