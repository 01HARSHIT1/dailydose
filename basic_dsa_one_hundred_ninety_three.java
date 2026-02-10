/**
 * Basic DSA Problems - Add Two Numbers (Linked List)
 * Two numbers represented as linked lists (digits reversed). Return sum as list.
 */
public class basic_dsa_one_hundred_ninety_three {

    // Problem: l1 and l2 represent numbers with digits in reverse order. Return l1 + l2 as list.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    /**
     * Add digit by digit, carry over. Dummy head, build result list.
     * Time O(max(m,n)), Space O(1) excluding result
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int a = l1 != null ? l1.val : 0;
            int b = l2 != null ? l2.val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            tail.next = new ListNode(sum % 10);
            tail = tail.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Add Two Numbers");
        System.out.println("=".repeat(60));

        ListNode l1 = new ListNode(2);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);
        ListNode l2 = new ListNode(5);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);
        ListNode sum = addTwoNumbers(l1, l2);
        StringBuilder sb = new StringBuilder();
        while (sum != null) {
            sb.append(sum.val);
            sum = sum.next;
        }
        System.out.println("342 + 465 -> " + sb.reverse().toString());
    }
}
