/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_one {

    // Problem 1: Linked List Cycle
    // Return true if following next pointers from head eventually revisits a node.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Floyd: slow moves 1 step, fast moves 2; meet iff cycle exists
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean hasCycle(ListNode head) {
        if (head == null) {
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
        a.next.next.next.next = a.next;
        System.out.println("cycle 3,2,0,-4 -> " + hasCycle(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        System.out.println("no cycle -> " + hasCycle(b));

        System.out.println("null -> " + hasCycle(null));
    }
}
