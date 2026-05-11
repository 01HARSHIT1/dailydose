/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_five {

    // Problem 1: Palindrome Linked List
    // O(1) extra space: reverse second half, compare, then restore links.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Cut after first half, reverse tail, match front; re-attach reversed tail
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        ListNode endFirst = endOfFirstHalf(head);
        ListNode secondStart = reverse(endFirst.next);
        endFirst.next = null;

        ListNode p1 = head;
        ListNode p2 = secondStart;
        boolean ok = true;
        while (p2 != null) {
            if (p1.val != p2.val) {
                ok = false;
            }
            p1 = p1.next;
            p2 = p2.next;
        }

        endFirst.next = reverse(secondStart);
        return ok;
    }

    private static ListNode endOfFirstHalf(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    private static ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
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
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Palindrome Linked List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(2);
        a.next.next.next = new ListNode(1);
        System.out.println("1,2,2,1 -> " + isPalindrome(a));
        System.out.println("restored -> " + toStr(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        System.out.println("1,2 -> " + isPalindrome(b));

        System.out.println("null -> " + isPalindrome(null));
    }
}
