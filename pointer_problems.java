import java.util.*;

/**
 * Pointer/Reference DSA Interview Problems
 * Collection of common pointer/reference problems with solutions
 * Note: Java uses object references, not explicit pointers
 */

// Definition for a singly-linked list node
class ListNode {
    int val;
    ListNode next;
    
    ListNode() {}
    
    ListNode(int val) {
        this.val = val;
    }
    
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class pointer_problems {
    
    // Helper function to create linked list from array
    public static ListNode createLinkedList(int[] arr) {
        if (arr.length == 0) {
            return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        return head;
    }
    
    // Helper function to convert linked list to array
    public static int[] linkedListToArray(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode current = head;
        while (current != null) {
            result.add(current.val);
            current = current.next;
        }
        return result.stream().mapToInt(i -> i).toArray();
    }
    
    // Helper function to print array
    private static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
    
    // Problem 1: Reverse Linked List
    // Reverse a singly linked list iteratively
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode reverseLinkedList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        
        while (current != null) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }
    
    // Problem 2: Reverse Linked List (Recursive)
    // Reverse a singly linked list recursively
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n) due to recursion stack
     */
    public static ListNode reverseLinkedListRecursive(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode reversedHead = reverseLinkedListRecursive(head.next);
        head.next.next = head;
        head.next = null;
        
        return reversedHead;
    }
    
    // Problem 3: Merge Two Sorted Lists
    // Merge two sorted linked lists and return as a new sorted list
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        current.next = (l1 != null) ? l1 : l2;
        
        return dummy.next;
    }
    
    // Problem 4: Detect Cycle in Linked List (Floyd's Cycle Detection)
    // Determine if linked list has a cycle
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (fast != null && fast.next != null) {
            if (slow == fast) {
                return true;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return false;
    }
    
    // Problem 5: Find Middle of Linked List
    // Return the middle node of a linked list
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }
    
    // Problem 6: Remove Duplicates from Sorted List
    // Remove all duplicates from sorted linked list
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
        
        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        
        return head;
    }
    
    // Problem 7: Remove Nth Node From End
    // Remove the nth node from the end of list
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        
        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }
        
        // Move both pointers until first reaches end
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        
        // Remove the nth node
        second.next = second.next.next;
        
        return dummy.next;
    }
    
    // Problem 8: Intersection of Two Linked Lists
    // Find the intersection node of two linked lists
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        
        ListNode ptrA = headA;
        ListNode ptrB = headB;
        
        while (ptrA != ptrB) {
            ptrA = (ptrA == null) ? headB : ptrA.next;
            ptrB = (ptrB == null) ? headA : ptrB.next;
        }
        
        return ptrA;
    }
    
    // Problem 9: Palindrome Linked List
    // Check if a linked list is a palindrome
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        
        // Find middle
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Reverse second half
        ListNode secondHalf = reverseLinkedList(slow.next);
        ListNode firstHalf = head;
        
        // Compare
        while (secondHalf != null) {
            if (firstHalf.val != secondHalf.val) {
                return false;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }
        
        return true;
    }
    
    // Problem 10: Add Two Numbers
    // Add two numbers represented as linked lists (digits in reverse order)
    /**
     * Time Complexity: O(max(m, n))
     * Space Complexity: O(max(m, n))
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;
        
        while (l1 != null || l2 != null || carry != 0) {
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;
            
            int total = val1 + val2 + carry;
            carry = total / 10;
            current.next = new ListNode(total % 10);
            current = current.next;
            
            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;
        }
        
        return dummy.next;
    }
    
    // Problem 11: Reverse Nodes in k-Group
    // Reverse nodes in groups of k
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode node = head;
        for (int i = 0; i < k; i++) {
            if (node == null) {
                return head;
            }
            node = node.next;
        }
        
        ListNode newHead = reverseGroup(head, node);
        head.next = reverseKGroup(node, k);
        
        return newHead;
    }
    
    private static ListNode reverseGroup(ListNode start, ListNode end) {
        ListNode prev = end;
        ListNode current = start;
        while (current != end) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    
    // Problem 12: Swap Nodes in Pairs
    // Swap every two adjacent nodes
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        
        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = prev.next.next;
            
            prev.next = second;
            first.next = second.next;
            second.next = first;
            
            prev = first;
        }
        
        return dummy.next;
    }
    
    // Problem 13: Remove Linked List Elements
    // Remove all nodes with given value
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        
        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        
        return dummy.next;
    }
    
    // Problem 14: Odd Even Linked List
    // Group all odd nodes together followed by even nodes
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static ListNode oddEvenList(ListNode head) {
        if (head == null) {
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
    
    // Problem 15: Delete Node in Linked List
    // Delete a node (except tail) in O(1) time
    /**
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     * Note: Node is guaranteed not to be the tail
     */
    public static void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("Problem 1 - Reverse Linked List:");
        ListNode head1 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Original: ");
        printArray(linkedListToArray(head1));
        ListNode reversedHead = reverseLinkedList(head1);
        System.out.print("Reversed: ");
        printArray(linkedListToArray(reversedHead));
        
        System.out.println("\nProblem 2 - Merge Two Sorted Lists:");
        ListNode l1 = createLinkedList(new int[]{1, 2, 4});
        ListNode l2 = createLinkedList(new int[]{1, 3, 4});
        ListNode merged = mergeTwoLists(l1, l2);
        System.out.print("Merged: ");
        printArray(linkedListToArray(merged));
        
        System.out.println("\nProblem 3 - Find Middle of Linked List:");
        ListNode head2 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        ListNode middle = middleNode(head2);
        System.out.println("Middle: " + middle.val);
        
        System.out.println("\nProblem 4 - Remove Duplicates from Sorted List:");
        ListNode head3 = createLinkedList(new int[]{1, 1, 2, 3, 3});
        ListNode noDuplicates = deleteDuplicates(head3);
        System.out.print("After removing duplicates: ");
        printArray(linkedListToArray(noDuplicates));
        
        System.out.println("\nProblem 5 - Remove Nth Node From End:");
        ListNode head4 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        ListNode removed = removeNthFromEnd(head4, 2);
        System.out.print("After removing 2nd from end: ");
        printArray(linkedListToArray(removed));
        
        System.out.println("\nProblem 6 - Palindrome Linked List:");
        ListNode head5 = createLinkedList(new int[]{1, 2, 2, 1});
        System.out.println("Is palindrome: " + isPalindrome(head5));
        
        System.out.println("\nProblem 7 - Add Two Numbers:");
        ListNode num1 = createLinkedList(new int[]{2, 4, 3});
        ListNode num2 = createLinkedList(new int[]{5, 6, 4});
        ListNode sumList = addTwoNumbers(num1, num2);
        System.out.print("Sum: ");
        printArray(linkedListToArray(sumList));
        
        System.out.println("\nProblem 8 - Swap Nodes in Pairs:");
        ListNode head6 = createLinkedList(new int[]{1, 2, 3, 4});
        ListNode swapped = swapPairs(head6);
        System.out.print("After swapping pairs: ");
        printArray(linkedListToArray(swapped));
        
        System.out.println("\nProblem 9 - Remove Linked List Elements:");
        ListNode head7 = createLinkedList(new int[]{1, 2, 6, 3, 4, 5, 6});
        ListNode removedVal = removeElements(head7, 6);
        System.out.print("After removing 6: ");
        printArray(linkedListToArray(removedVal));
        
        System.out.println("\nProblem 10 - Odd Even Linked List:");
        ListNode head8 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        ListNode oddEven = oddEvenList(head8);
        System.out.print("Odd even list: ");
        printArray(linkedListToArray(oddEven));
    }
}
