/**
 * Basic DSA Problems - Palindrome Linked List
 * Check if linked list is palindrome in O(n) time, O(1) space
 */
public class basic_dsa_two_hundred_eighty_four {

    // Problem: Return true if linked list reads same forward and backward.
    // O(n) time, O(1) extra space.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; }
    }

    /**
     * Find mid, reverse second half, compare first and second halves.
     * Time O(n), Space O(1)
     */
    public static boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode half = reverse(slow);
        while (half != null) {
            if (head.val != half.val) return false;
            head = head.next;
            half = half.next;
        }
        return true;
    }

    static ListNode reverse(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Palindrome Linked List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(2);
        a.next.next.next = new ListNode(1);
        System.out.println("1->2->2->1 -> " + isPalindrome(a));

        ListNode b = new ListNode(1);
        b.next = new ListNode(2);
        System.out.println("1->2 -> " + isPalindrome(b));
    }
}
