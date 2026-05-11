/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_one {

    // Problem 1: Reverse Linked List II
    // Reverse nodes from position left to right inclusive (1-indexed). O(1) extra space.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Move node after cur to front of segment (right-left times)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode before = dummy;

        for (int i = 1; i < left; i++) {
            before = before.next;
        }

        ListNode cur = before.next;
        for (int i = 0; i < right - left; i++) {
            ListNode nxt = cur.next;
            cur.next = nxt.next;
            nxt.next = before.next;
            before.next = nxt;
        }

        return dummy.next;
    }

    private static String toStr(ListNode h) {
        StringBuilder sb = new StringBuilder();
        for (ListNode p = h; p != null; p = p.next) {
            if (sb.length() > 0) {
                sb.append("->");
            }
            sb.append(p.val);
        }
        return sb.length() == 0 ? "(empty)" : sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse Linked List II");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        System.out.println("left=2 right=4 -> " + toStr(reverseBetween(head, 2, 4)));

        ListNode a = new ListNode(5);
        System.out.println("single range -> " + toStr(reverseBetween(a, 1, 1)));

        System.out.println("null -> " + reverseBetween(null, 1, 1));
    }
}
