import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_four {

    // Problem 1: Add Two Numbers II
    // Digits stored MSB first; return sum list MSB first (non-negative, no leading zeros except 0).

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Push both lists on stacks; build result by prepending (sum with carry)
     * Time Complexity: O(m + n)
     * Space Complexity: O(m + n) for stacks
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Deque<Integer> s1 = new ArrayDeque<>();
        Deque<Integer> s2 = new ArrayDeque<>();

        for (ListNode p = l1; p != null; p = p.next) {
            s1.push(p.val);
        }
        for (ListNode p = l2; p != null; p = p.next) {
            s2.push(p.val);
        }

        ListNode head = null;
        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int a = s1.isEmpty() ? 0 : s1.pop();
            int b = s2.isEmpty() ? 0 : s2.pop();
            int sum = a + b + carry;
            ListNode node = new ListNode(sum % 10);
            node.next = head;
            head = node;
            carry = sum / 10;
        }

        return head;
    }

    private static String toStr(ListNode h) {
        StringBuilder sb = new StringBuilder();
        for (ListNode p = h; p != null; p = p.next) {
            if (sb.length() > 0) {
                sb.append("->");
            }
            sb.append(p.val);
        }
        return sb.length() == 0 ? "(empty)" : sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Add Two Numbers II");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(7);
        a.next = new ListNode(2);
        a.next.next = new ListNode(4);
        a.next.next.next = new ListNode(3);

        ListNode b = new ListNode(5);
        b.next = new ListNode(6);
        b.next.next = new ListNode(4);

        System.out.println("7243+564 -> " + toStr(addTwoNumbers(a, b)));

        ListNode z = new ListNode(0);
        ListNode o = new ListNode(0);
        System.out.println("0+0 -> " + toStr(addTwoNumbers(z, o)));

        System.out.println("null+null -> " + addTwoNumbers(null, null));
    }
}
