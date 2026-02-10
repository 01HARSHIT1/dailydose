/**
 * Basic DSA Problems - Merge Two Sorted Lists
 * Merge two sorted linked lists into one sorted list
 */
public class basic_dsa_one_hundred_eighty_eight {

    // Problem: Two sorted linked lists. Return head of merged sorted list.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * Dummy head; repeatedly attach smaller of list1.val vs list2.val; attach remaining.
     * Time O(n+m), Space O(1)
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

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Merge Two Sorted Lists");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(4);
        ListNode b = new ListNode(1);
        b.next = new ListNode(3);
        b.next.next = new ListNode(4);
        ListNode merged = mergeTwoLists(a, b);
        StringBuilder sb = new StringBuilder();
        while (merged != null) {
            sb.append(merged.val).append(" ");
            merged = merged.next;
        }
        System.out.println("Merged -> " + sb.toString().trim());
    }
}
