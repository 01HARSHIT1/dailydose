/**
 * Basic DSA - Linked List: Reverse Linked List
 * Reverse a singly linked list iteratively.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
public class basic_dsa_linked_list_reverse {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode reverseList(ListNode head) {
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

    private static ListNode fromArray(int[] a) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (int x : a) {
            tail.next = new ListNode(x);
            tail = tail.next;
        }
        return dummy.next;
    }

    private static String toString(ListNode head) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        ListNode cur = head;
        while (cur != null) {
            sb.append(cur.val);
            cur = cur.next;
            if (cur != null) sb.append(", ");
        }
        sb.append("]");
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Linked List");
        System.out.println("=".repeat(60));

        ListNode head = fromArray(new int[]{1, 2, 3, 4, 5});
        System.out.println("Original: " + toString(head));
        ListNode rev = reverseList(head);
        System.out.println("Reversed: " + toString(rev));
    }
}

