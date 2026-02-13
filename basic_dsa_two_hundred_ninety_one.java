/**
 * Basic DSA Problems - Intersection of Two Linked Lists
 * Find node at which two lists intersect
 */
public class basic_dsa_two_hundred_ninety_one {

    // Problem: Two singly linked lists. Find node at which they intersect (or null).
    // No cycles. Must be O(1) space.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; }
    }

    /**
     * Two pointers: traverse each list, when reach end switch to other head.
     * They meet at intersection (or null) after 2 traversals.
     * Time O(m+n), Space O(1)
     */
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA, b = headB;
        while (a != b) {
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Intersection of Two Linked Lists");
        System.out.println("=".repeat(60));

        ListNode common = new ListNode(8);
        common.next = new ListNode(4);
        common.next.next = new ListNode(5);

        ListNode headA = new ListNode(4);
        headA.next = new ListNode(1);
        headA.next.next = common;

        ListNode headB = new ListNode(5);
        headB.next = new ListNode(6);
        headB.next.next = new ListNode(1);
        headB.next.next.next = common;

        System.out.println("Intersection node val -> " + getIntersectionNode(headA, headB).val);
    }
}
