/**
 * Basic DSA Problems - Delete Node in a Linked List
 * Delete node without head reference
 */
public class basic_dsa_two_hundred_eighty_six {

    // Problem: Given node to delete (not tail). Delete it in O(1). No head ref.
    // Copy next's val to node, then skip next.

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; }
    }

    /**
     * Copy next node's value to this node, then point to next.next.
     * Time O(1), Space O(1)
     */
    public static void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Delete Node in a Linked List");
        System.out.println("=".repeat(60));

        ListNode head = new ListNode(4);
        head.next = new ListNode(5);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(9);

        deleteNode(head.next);
        StringBuilder sb = new StringBuilder();
        ListNode p = head;
        while (p != null) {
            sb.append(p.val).append(p.next != null ? "->" : "");
            p = p.next;
        }
        System.out.println("4->5->1->9, delete 5 -> " + sb);
    }
}
