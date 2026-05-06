/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_two {

    // Problem 1: Middle of the Linked List
    // Given the head of a singly linked list, return the middle node.
    // If there are two middle nodes, return the second middle node.
    //
    // Example:
    // [1,2,3,4,5] -> node with value 3
    // [1,2,3,4,5,6] -> node with value 4

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    /**
     * Fast/slow pointers
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    private static String listFromNode(ListNode node) {
        if (node == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        ListNode cur = node;
        while (cur != null) {
            if (sb.length() > 1) {
                sb.append(", ");
            }
            sb.append(cur.val);
            cur = cur.next;
        }
        sb.append("]");
        return sb.toString();
    }

    private static ListNode fromArray(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        ListNode h = new ListNode(arr[0]);
        ListNode t = h;
        for (int i = 1; i < arr.length; i++) {
            t.next = new ListNode(arr[i]);
            t = t.next;
        }
        return h;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Middle of the Linked List");
        System.out.println("=".repeat(60));

        ListNode a = fromArray(new int[]{1, 2, 3, 4, 5});
        System.out.println("middle of [1..5] -> " + listFromNode(middleNode(a)));

        ListNode b = fromArray(new int[]{1, 2, 3, 4, 5, 6});
        System.out.println("middle of [1..6] -> " + listFromNode(middleNode(b)));

        ListNode c = fromArray(new int[]{1});
        System.out.println("middle of [1] -> " + listFromNode(middleNode(c)));

        System.out.println("middle of [] -> " + (middleNode(null) == null));
    }
}
