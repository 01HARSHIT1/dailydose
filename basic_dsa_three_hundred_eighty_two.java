/**
 * Basic DSA Problems - Linked List Random Node (LeetCode 382)
 * getRandom() returns random node value with equal probability
 */
public class basic_dsa_three_hundred_eighty_two {

    // Problem: getRandom() - each node has equal probability.

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    static class Solution {
        ListNode head;
        java.util.Random rnd = new java.util.Random();

        Solution(ListNode head) { this.head = head; }

        /**
         * Reservoir sampling: for node i, replace with prob 1/i.
         * Time O(n), Space O(1)
         */
        public int getRandom() {
            int out = head.val;
            ListNode cur = head.next;
            for (int i = 2; cur != null; i++, cur = cur.next)
                if (rnd.nextInt(i) == 0) out = cur.val;
            return out;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Linked List Random Node");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        Solution sol = new Solution(head);
        System.out.println("List [1,2,3], getRandom x5: " + sol.getRandom() + " " + sol.getRandom()
                + " " + sol.getRandom() + " " + sol.getRandom() + " " + sol.getRandom());
    }
}
