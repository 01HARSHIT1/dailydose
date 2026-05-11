/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_three {

    // Problem 1: Remove Nth Node From End of List
    // Remove one node so the list has length decreased by 1; n is valid (1..length).

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Fast pointer n+1 ahead of slow from dummy; when fast passes end, slow.next is target
     * Time Complexity: O(L)
     * Space Complexity: O(1)
     */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy;
        ListNode slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return dummy.next;
    }

    private static String toStr(ListNode head) {
        StringBuilder sb = new StringBuilder();
        for (ListNode p = head; p != null; p = p.next) {
            if (sb.length() > 0) {
                sb.append(" -> ");
            }
            sb.append(p.val);
        }
        return sb.length() == 0 ? "(empty)" : sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Remove Nth Node From End");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("remove 2nd from end -> " + toStr(removeNthFromEnd(head, 2)));

        ListNode one = new ListNode(1);
        System.out.println("single n=1 -> " + toStr(removeNthFromEnd(one, 1)));
    }
}
