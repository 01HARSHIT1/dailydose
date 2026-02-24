/**
 * Basic DSA Problems - Convert BST to Sorted Doubly Linked List (LeetCode 426)
 * In-place: left=prev, right=next. Circular. Return smallest (head).
 */
public class basic_dsa_four_hundred_twenty_six {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    static Node prev, head;

    /**
     * In-order DFS: link prev->root, root->prev. Then circular: last->head, head->last.
     * Time O(n), Space O(h)
     */
    public static Node treeToDoublyList(Node root) {
        if (root == null) return null;
        prev = null; head = null;
        dfs(root);
        prev.right = head;
        head.left = prev;
        return head;
    }

    private static void dfs(Node root) {
        if (root == null) return;
        dfs(root.left);
        if (prev != null) {
            prev.right = root;
            root.left = prev;
        } else head = root;
        prev = root;
        dfs(root.right);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Convert BST to Sorted Doubly Linked List");
        System.out.println("=".repeat(60));

        Node r1 = new Node(4);
        r1.left = new Node(2); r1.right = new Node(5);
        r1.left.left = new Node(1); r1.left.right = new Node(3);
        Node h1 = treeToDoublyList(r1);
        System.out.print("[4,2,5,1,3] -> ");
        printList(h1);

        Node r2 = new Node(2);
        r2.left = new Node(1); r2.right = new Node(3);
        Node h2 = treeToDoublyList(r2);
        System.out.print("[2,1,3] -> ");
        printList(h2);
    }

    private static void printList(Node head) {
        if (head == null) { System.out.println("[]"); return; }
        Node p = head;
        do {
            System.out.print(p.val + (p.right == head ? "" : ","));
            p = p.right;
        } while (p != head);
        System.out.println();
    }
}
