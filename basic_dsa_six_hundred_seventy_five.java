/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_five {

    // Problem 1: Reorder List
    // L0 -> L1 -> ... -> Ln  becomes  L0 -> Ln -> L1 -> Ln-1 -> ...

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Split after first half, reverse second half, interleave
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode second = reverse(slow.next);
        slow.next = null;

        ListNode first = head;
        while (second != null) {
            ListNode t1 = first.next;
            ListNode t2 = second.next;
            first.next = second;
            second.next = t1;
            first = t1;
            second = t2;
        }
    }

    private static ListNode reverse(ListNode h) {
        ListNode prev = null;
        ListNode cur = h;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
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
        System.out.println("Problem 1: Reorder List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(3);
        a.next.next.next = new ListNode(4);
        reorderList(a);
        System.out.println("1..4 -> " + toStr(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        b.next.next = new ListNode(3);
        b.next.next.next = new ListNode(4);
        b.next.next.next.next = new ListNode(5);
        reorderList(b);
        System.out.println("1..5 -> " + toStr(b));
    }
}
