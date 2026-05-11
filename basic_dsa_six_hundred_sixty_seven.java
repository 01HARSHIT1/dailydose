/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixty_seven {

    // Problem 1: Odd Even Linked List
    // 1-indexed: all odd-position nodes first, then even-position nodes; O(1) space.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Weave odd chain and even chain; connect odd tail to even head
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;

        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }

        odd.next = evenHead;
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
        System.out.println("Problem 1: Odd Even Linked List");
        System.out.println("=".repeat(60));

        ListNode a = new ListNode(1);
        a.next = new ListNode(2);
        a.next.next = new ListNode(3);
        a.next.next.next = new ListNode(4);
        a.next.next.next.next = new ListNode(5);
        System.out.println("1..5 -> " + toStr(oddEvenList(a)));

        ListNode b = new ListNode(2);
        b.next = new ListNode(1);
        b.next.next = new ListNode(3);
        b.next.next.next = new ListNode(5);
        b.next.next.next.next = new ListNode(6);
        b.next.next.next.next.next = new ListNode(4);
        b.next.next.next.next.next.next = new ListNode(7);
        System.out.println("sample 2 -> " + toStr(oddEvenList(b)));

        System.out.println("null -> " + oddEvenList(null));
    }
}
