/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_four {

    // Problem 1: Intersection of Two Linked Lists
    // If two lists share a common suffix (same nodes by reference), return first shared node; else null.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Two walkers: at end of A switch to B, and vice versa — equalizes path length
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode a = headA;
        ListNode b = headB;
        while (a != b) {
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        }
        return a;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Intersection of Two Linked Lists");
        System.out.println("=".repeat(60));

        ListNode tail = new ListNode(8);
        tail.next = new ListNode(4);
        tail.next.next = new ListNode(5);

        ListNode la = new ListNode(4);
        la.next = new ListNode(1);
        la.next.next = tail;

        ListNode lb = new ListNode(5);
        lb.next = new ListNode(6);
        lb.next.next = new ListNode(1);
        lb.next.next.next = tail;

        ListNode meet = getIntersectionNode(la, lb);
        System.out.println("meet at 8 -> " + (meet != null && meet.val == 8 && meet == tail));

        ListNode x = new ListNode(1);
        ListNode y = new ListNode(2);
        System.out.println("no share -> " + (getIntersectionNode(x, y) == null));

        System.out.println("null heads -> " + (getIntersectionNode(null, la) == null));
    }
}
