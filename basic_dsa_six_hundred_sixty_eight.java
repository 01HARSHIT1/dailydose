/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_eight {

    // Problem 1: Remove Duplicates from Sorted List
    // Sorted ascending; keep one node per value; reuse list in-place.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * One pointer: if next has same val, skip it; else advance
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (cur.val == cur.next.val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return head;
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
        System.out.println("Problem 1: Remove Duplicates from Sorted List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(1);
        a.next.next = new ListNode(2);
        System.out.println("1,1,2 -> " + toStr(deleteDuplicates(a)));

        ListNode b = new ListNode(1);
        b.next = new ListNode(1);
        b.next.next = new ListNode(2);
        b.next.next.next = new ListNode(3);
        b.next.next.next.next = new ListNode(3);
        System.out.println("1,1,2,3,3 -> " + toStr(deleteDuplicates(b)));

        System.out.println("null -> " + deleteDuplicates(null));
    }
}
