#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Pointer DSA Interview Problems
 * Collection of common pointer problems with solutions
 * C uses explicit pointers
 */

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to create linked list from array
struct ListNode* createLinkedList(int* arr, int size) {
    if (size == 0) {
        return NULL;
    }
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printLinkedList(struct ListNode* head) {
    printf("[");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Helper function to free linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

// Problem 1: Reverse Linked List
// Reverse a singly linked list iteratively
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    while (current != NULL) {
        struct ListNode* nextNode = current->next;
        current->next = prev;
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
struct ListNode* reverseLinkedListRecursive(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* reversedHead = reverseLinkedListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return reversedHead;
}

// Problem 3: Merge Two Sorted Lists
// Merge two sorted linked lists and return as a new sorted list
/**
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = createNode(0);
    struct ListNode* current = dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    current->next = (l1 != NULL) ? l1 : l2;
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Problem 4: Detect Cycle in Linked List (Floyd's Cycle Detection)
// Determine if linked list has a cycle
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

// Problem 5: Find Middle of Linked List
// Return the middle node of a linked list
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Problem 6: Remove Duplicates from Sorted List
// Remove all duplicates from sorted linked list
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* first = dummy;
    struct ListNode* second = dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node
    struct ListNode* temp = second->next;
    second->next = second->next->next;
    free(temp);
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Problem 8: Intersection of Two Linked Lists
// Find the intersection node of two linked lists
/**
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;
    
    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }
    
    return ptrA;
}

// Problem 9: Palindrome Linked List
// Check if a linked list is a palindrome
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    // Find middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    struct ListNode* secondHalf = reverseLinkedList(slow->next);
    struct ListNode* firstHalf = head;
    
    // Compare
    bool result = true;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    // Restore the list (optional)
    reverseLinkedList(slow->next);
    
    return result;
}

// Problem 10: Add Two Numbers
// Add two numbers represented as linked lists (digits in reverse order)
/**
 * Time Complexity: O(max(m, n))
 * Space Complexity: O(max(m, n))
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = createNode(0);
    struct ListNode* current = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        int total = val1 + val2 + carry;
        carry = total / 10;
        current->next = createNode(total % 10);
        current = current->next;
        
        l1 = (l1 != NULL) ? l1->next : NULL;
        l2 = (l2 != NULL) ? l2->next : NULL;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Problem 11: Reverse Nodes in k-Group
// Reverse nodes in groups of k
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* node = head;
    for (int i = 0; i < k; i++) {
        if (node == NULL) {
            return head;
        }
        node = node->next;
    }
    
    struct ListNode* newHead = reverseGroup(head, node);
    head->next = reverseKGroup(node, k);
    
    return newHead;
}

struct ListNode* reverseGroup(struct ListNode* start, struct ListNode* end) {
    struct ListNode* prev = end;
    struct ListNode* current = start;
    while (current != end) {
        struct ListNode* nextNode = current->next;
        current->next = prev;
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
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;
        
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        prev = first;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Problem 13: Remove Linked List Elements
// Remove all nodes with given value
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode* current = dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Problem 14: Odd Even Linked List
// Group all odd nodes together followed by even nodes
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;
    
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    
    return head;
}

// Problem 15: Delete Node in Linked List
// Delete a node (except tail) in O(1) time
/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * Note: Node is guaranteed not to be the tail
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    struct ListNode* temp = node->next;
    node->next = node->next->next;
    free(temp);
}

// Test cases
int main() {
    printf("Problem 1 - Reverse Linked List:\n");
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createLinkedList(arr1, 5);
    printf("Original: ");
    printLinkedList(head1);
    struct ListNode* reversedHead = reverseLinkedList(head1);
    printf("Reversed: ");
    printLinkedList(reversedHead);
    freeLinkedList(reversedHead);
    
    printf("\nProblem 2 - Merge Two Sorted Lists:\n");
    int arr2a[] = {1, 2, 4};
    int arr2b[] = {1, 3, 4};
    struct ListNode* l1 = createLinkedList(arr2a, 3);
    struct ListNode* l2 = createLinkedList(arr2b, 3);
    struct ListNode* merged = mergeTwoLists(l1, l2);
    printf("Merged: ");
    printLinkedList(merged);
    freeLinkedList(merged);
    
    printf("\nProblem 3 - Find Middle of Linked List:\n");
    int arr3[] = {1, 2, 3, 4, 5};
    struct ListNode* head2 = createLinkedList(arr3, 5);
    struct ListNode* middle = middleNode(head2);
    printf("Middle: %d\n", middle->val);
    freeLinkedList(head2);
    
    printf("\nProblem 4 - Remove Duplicates from Sorted List:\n");
    int arr4[] = {1, 1, 2, 3, 3};
    struct ListNode* head3 = createLinkedList(arr4, 5);
    struct ListNode* noDuplicates = deleteDuplicates(head3);
    printf("After removing duplicates: ");
    printLinkedList(noDuplicates);
    freeLinkedList(noDuplicates);
    
    printf("\nProblem 5 - Remove Nth Node From End:\n");
    int arr5[] = {1, 2, 3, 4, 5};
    struct ListNode* head4 = createLinkedList(arr5, 5);
    struct ListNode* removed = removeNthFromEnd(head4, 2);
    printf("After removing 2nd from end: ");
    printLinkedList(removed);
    freeLinkedList(removed);
    
    printf("\nProblem 6 - Palindrome Linked List:\n");
    int arr6[] = {1, 2, 2, 1};
    struct ListNode* head5 = createLinkedList(arr6, 4);
    printf("Is palindrome: %s\n", isPalindrome(head5) ? "true" : "false");
    freeLinkedList(head5);
    
    printf("\nProblem 7 - Add Two Numbers:\n");
    int arr7a[] = {2, 4, 3};
    int arr7b[] = {5, 6, 4};
    struct ListNode* num1 = createLinkedList(arr7a, 3);
    struct ListNode* num2 = createLinkedList(arr7b, 3);
    struct ListNode* sumList = addTwoNumbers(num1, num2);
    printf("Sum: ");
    printLinkedList(sumList);
    freeLinkedList(num1);
    freeLinkedList(num2);
    freeLinkedList(sumList);
    
    printf("\nProblem 8 - Swap Nodes in Pairs:\n");
    int arr8[] = {1, 2, 3, 4};
    struct ListNode* head6 = createLinkedList(arr8, 4);
    struct ListNode* swapped = swapPairs(head6);
    printf("After swapping pairs: ");
    printLinkedList(swapped);
    freeLinkedList(swapped);
    
    printf("\nProblem 9 - Remove Linked List Elements:\n");
    int arr9[] = {1, 2, 6, 3, 4, 5, 6};
    struct ListNode* head7 = createLinkedList(arr9, 7);
    struct ListNode* removedVal = removeElements(head7, 6);
    printf("After removing 6: ");
    printLinkedList(removedVal);
    freeLinkedList(removedVal);
    
    printf("\nProblem 10 - Odd Even Linked List:\n");
    int arr10[] = {1, 2, 3, 4, 5};
    struct ListNode* head8 = createLinkedList(arr10, 5);
    struct ListNode* oddEven = oddEvenList(head8);
    printf("Odd even list: ");
    printLinkedList(oddEven);
    freeLinkedList(oddEven);
    
    return 0;
}
