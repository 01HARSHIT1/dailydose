/**
 * Basic DSA - Linked List: Merge Two Sorted Lists
 * Merge two sorted singly linked lists and return the merged list.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1) extra
 */
public class basic_dsa_linked_list_merge_two_sorted {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode mergeTwoLists(ListNode a, ListNode b) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (a != null && b != null) {
            if (a.val <= b.val) {
                tail.next = a;
                a = a.next;
            } else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        tail.next = (a != null) ? a : b;
        return dummy.next;
    }

    private static ListNode fromArray(int[] arr) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (int x : arr) {
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
        System.out.println("Problem: Merge Two Sorted Lists");
        System.out.println("=".repeat(60));

        ListNode l1 = fromArray(new int[]{1, 2, 4});
        ListNode l2 = fromArray(new int[]{1, 3, 4});
        System.out.println("L1: " + toString(l1));
        System.out.println("L2: " + toString(l2));

        ListNode merged = mergeTwoLists(l1, l2);
        System.out.println("Merged: " + toString(merged)); // [1, 1, 2, 3, 4, 4]
    }
}

