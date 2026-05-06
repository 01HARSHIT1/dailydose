/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_one {

    // Problem 1: Reverse Linked List
    // Given the head of a singly linked list, reverse the list and return the new head.
    //
    // Example:
    // head = [1,2,3,4,5] -> [5,4,3,2,1]

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    /**
     * Iterative reversal with three pointers
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    private static String listToString(ListNode head) {
        if (head == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        ListNode cur = head;
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
        System.out.println("Problem 1: Reverse Linked List");
        System.out.println("=".repeat(60));

        ListNode a = fromArray(new int[]{1, 2, 3, 4, 5});
        System.out.println("reverse -> " + listToString(reverseList(a)));

        ListNode b = fromArray(new int[]{1, 2});
        System.out.println("reverse [1,2] -> " + listToString(reverseList(b)));

        System.out.println("reverse [] -> " + listToString(reverseList(null)));
    }
}
