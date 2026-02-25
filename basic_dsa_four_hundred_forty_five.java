/**
 * Basic DSA Problems - Add Two Numbers II (LeetCode 445)
 * Two linked lists MSB first. Add and return sum as list. No reversing input.
 */
public class basic_dsa_four_hundred_forty_five {

    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int v) { val = v; }
        ListNode(int v, ListNode n) { val = v; next = n; }
    }

    // Problem: [7,2,4,3] + [5,6,4] = [7,8,0,7]

    /**
     * Stacks to get LSB first. Add with carry, prepend to result.
     * Time O(m+n), Space O(m+n)
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        java.util.Deque<Integer> s1 = new java.util.ArrayDeque<>();
        java.util.Deque<Integer> s2 = new java.util.ArrayDeque<>();
        for (; l1 != null; l1 = l1.next) s1.push(l1.val);
        for (; l2 != null; l2 = l2.next) s2.push(l2.val);
        ListNode dummy = new ListNode();
        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int s = (s1.isEmpty() ? 0 : s1.pop()) + (s2.isEmpty() ? 0 : s2.pop()) + carry;
            dummy.next = new ListNode(s % 10, dummy.next);
            carry = s / 10;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Add Two Numbers II");
        System.out.println("=".repeat(60));

        ListNode l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
        ListNode sum = addTwoNumbers(l1, l2);
        StringBuilder sb = new StringBuilder();
        for (ListNode p = sum; p != null; p = p.next) sb.append(p.val);
        System.out.println("[7,2,4,3] + [5,6,4] -> " + sb);

        ListNode a = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode b = new ListNode(5, new ListNode(6, new ListNode(4)));
        ListNode s2 = addTwoNumbers(a, b);
        sb = new StringBuilder();
        for (ListNode p = s2; p != null; p = p.next) sb.append(p.val);
        System.out.println("[2,4,3] + [5,6,4] -> " + sb);
    }
}
