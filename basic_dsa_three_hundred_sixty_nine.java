/**
 * Basic DSA Problems - Plus One Linked List (LeetCode 369)
 * Add 1 to number represented as reversed digit linked list
 */
public class basic_dsa_three_hundred_sixty_nine {

    // Problem: Head is LSD. Add 1 to the number. Return new head.

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * First non-9 from head = where carry stops. Increment it, set 9s before to 0.
     * If all 9s, set all to 0 and append 1.
     * Time O(n), Space O(1)
     */
    public static ListNode plusOne(ListNode head) {
        ListNode nonNine = null, cur = head;
        while (cur != null) {
            if (cur.val != 9) { nonNine = cur; break; }
            cur = cur.next;
        }
        if (nonNine == null) {
            cur = head;
            while (cur != null) { cur.val = 0; cur = cur.next; }
            cur = head;
            while (cur.next != null) cur = cur.next;
            cur.next = new ListNode(1);
            return head;
        }
        nonNine.val++;
        cur = head;
        while (cur != nonNine) { cur.val = 0; cur = cur.next; }
        return head;
    }

    static ListNode toList(int[] a) {
        ListNode dummy = new ListNode(0), t = dummy;
        for (int x : a) { t.next = new ListNode(x); t = t.next; }
        return dummy.next;
    }

    static String fromList(ListNode n) {
        StringBuilder sb = new StringBuilder();
        while (n != null) { sb.append(n.val); n = n.next; }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Plus One Linked List");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + fromList(plusOne(toList(new int[]{1,2,3}))));
        System.out.println("[9,9,9] -> " + fromList(plusOne(toList(new int[]{9,9,9}))));
    }
}
