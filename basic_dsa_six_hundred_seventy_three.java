/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_three {

    // Problem 1: Insertion Sort List
    // Sort ascending by repeatedly taking the next input node and inserting into sorted prefix.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Dummy head of sorted part; for each node from old list, scan sorted list for insert point
     * Time Complexity: O(n^2)
     * Space Complexity: O(1)
     */
    public static ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);

        while (head != null) {
            ListNode next = head.next;
            ListNode p = dummy;
            while (p.next != null && p.next.val < head.val) {
                p = p.next;
            }
            head.next = p.next;
            p.next = head;
            head = next;
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
        System.out.println("Problem 1: Insertion Sort List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(4);
        a.next = new ListNode(2);
        a.next.next = new ListNode(1);
        a.next.next.next = new ListNode(3);
        System.out.println("4,2,1,3 -> " + toStr(insertionSortList(a)));

        ListNode b = new ListNode(-1);
        b.next = new ListNode(5);
        b.next.next = new ListNode(3);
        b.next.next.next = new ListNode(4);
        b.next.next.next.next = new ListNode(0);
        System.out.println("with negatives -> " + toStr(insertionSortList(b)));

        System.out.println("null -> " + insertionSortList(null));
    }
}
