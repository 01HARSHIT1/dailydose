/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty {

    // Problem 1: Merge Two Sorted Lists
    // Merge two sorted singly-linked lists and return one sorted list.
    //
    // Example:
    // list1 = [1,2,4], list2 = [1,3,4] -> [1,1,2,3,4,4]

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    /**
     * Dummy-head merge
     * Time Complexity: O(n + m)
     * Space Complexity: O(1)
     */
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }

        tail.next = list1 != null ? list1 : list2;
        return dummy.next;
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
        ListNode head = new ListNode(arr[0]);
        ListNode tail = head;
        for (int i = 1; i < arr.length; i++) {
            tail.next = new ListNode(arr[i]);
            tail = tail.next;
        }
        return head;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Merge Two Sorted Lists");
        System.out.println("=".repeat(60));

        ListNode a = fromArray(new int[]{1, 2, 4});
        ListNode b = fromArray(new int[]{1, 3, 4});
        System.out.println("merge -> " + listToString(mergeTwoLists(a, b)));

        ListNode e = fromArray(new int[]{});
        ListNode f = fromArray(new int[]{0});
        System.out.println("merge empty & [0] -> " + listToString(mergeTwoLists(e, f)));

        System.out.println("merge null lists -> " + listToString(mergeTwoLists(null, null)));
    }
}
