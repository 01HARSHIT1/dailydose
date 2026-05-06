/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_three {

    // Problem 1: Linked List Cycle
    // Given head, determine if the linked list has a cycle in it.
    // A cycle exists if some node can be reached again by following next.
    //
    // Use Floyd's cycle detection (tortoise and hare).

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    /**
     * Two pointers: slow moves 1 step, fast moves 2 steps
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Linked List Cycle");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(3);
        a.next = new ListNode(2);
        a.next.next = new ListNode(0);
        a.next.next.next = new ListNode(-4);
        a.next.next.next.next = a.next; // cycle to node 2
        System.out.println("cycle 3->2->0->-4->2 -> " + hasCycle(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        b.next.next = b; // cycle to 1
        System.out.println("cycle 1->2->1 -> " + hasCycle(b));

        ListNode c = new ListNode(1);
        System.out.println("no cycle single -> " + hasCycle(c));

        System.out.println("null -> " + hasCycle(null));
    }
}
