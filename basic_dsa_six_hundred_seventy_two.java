/**
 * Basic DSA Problems - One Fundamental Linked List Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_two {

    // Problem 1: Partition List
    // Nodes with value < x come before nodes with value >= x; preserve relative order within each part.

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int v) {
            val = v;
        }
    }

    /**
     * Two dummy chains: small and large tails; concatenate at end
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode partition(ListNode head, int x) {
        ListNode smallDummy = new ListNode(0);
        ListNode largeDummy = new ListNode(0);
        ListNode sTail = smallDummy;
        ListNode lTail = largeDummy;

        for (ListNode p = head; p != null; p = p.next) {
            if (p.val < x) {
                sTail.next = p;
                sTail = p;
            } else {
                lTail.next = p;
                lTail = p;
            }
        }

        lTail.next = null;
        sTail.next = largeDummy.next;
        return smallDummy.next;
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
        System.out.println("Problem 1: Partition List");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(1);
        head.next = new ListNode(4);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(2);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(2);

        System.out.println("x=3 -> " + toStr(partition(head, 3)));
        System.out.println("null x=0 -> " + partition(null, 0));
    }
}
