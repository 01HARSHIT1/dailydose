/**
 * Basic DSA Problems - Middle of the Linked List
 * Find the middle node of a linked list
 */
public class basic_dsa_three_hundred_eighteen {

    // Problem: Head of linked list. Return middle node. If two middles, return second.

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Fast and slow pointers: slow moves 1, fast moves 2. When fast reaches end, slow is middle.
     * Time O(n), Space O(1)
     */
    public static ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Middle of the Linked List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));
        System.out.println("[1,2,3,4,5] -> " + middleNode(a).val);

        ListNode b = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, null))))));
        System.out.println("[1,2,3,4,5,6] -> " + middleNode(b).val);
    }
}
