"""
Pointer/Reference DSA Interview Problems
Collection of common pointer/reference problems with solutions
Note: Python uses references, not explicit pointers
"""


# Definition for a singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __repr__(self):
        values = []
        node = self
        while node:
            values.append(str(node.val))
            node = node.next
        return " -> ".join(values) + " -> None"


# Helper function to create linked list from array
def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


# Helper function to convert linked list to array
def linked_list_to_array(head):
    result = []
    current = head
    while current:
        result.append(current.val)
        current = current.next
    return result


# Problem 1: Reverse Linked List
# Reverse a singly linked list iteratively
def reverse_linked_list(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev


# Problem 2: Reverse Linked List (Recursive)
# Reverse a singly linked list recursively
def reverse_linked_list_recursive(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if not head or not head.next:
        return head
    
    reversed_head = reverse_linked_list_recursive(head.next)
    head.next.next = head
    head.next = None
    
    return reversed_head


# Problem 3: Merge Two Sorted Lists
# Merge two sorted linked lists and return as a new sorted list
def merge_two_lists(l1, l2):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    dummy = ListNode(0)
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    current.next = l1 if l1 else l2
    
    return dummy.next


# Problem 4: Detect Cycle in Linked List (Floyd's Cycle Detection)
# Determine if linked list has a cycle
def has_cycle(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not head or not head.next:
        return False
    
    slow = head
    fast = head.next
    
    while fast and fast.next:
        if slow == fast:
            return True
        slow = slow.next
        fast = fast.next.next
    
    return False


# Problem 5: Find Middle of Linked List
# Return the middle node of a linked list
def middle_node(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow


# Problem 6: Remove Duplicates from Sorted List
# Remove all duplicates from sorted linked list
def delete_duplicates(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    current = head
    
    while current and current.next:
        if current.val == current.next.val:
            current.next = current.next.next
        else:
            current = current.next
    
    return head


# Problem 7: Remove Nth Node From End
# Remove the nth node from the end of list
def remove_nth_from_end(head, n):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    dummy = ListNode(0)
    dummy.next = head
    first = dummy
    second = dummy
    
    # Move first pointer n+1 steps ahead
    for _ in range(n + 1):
        first = first.next
    
    # Move both pointers until first reaches end
    while first:
        first = first.next
        second = second.next
    
    # Remove the nth node
    second.next = second.next.next
    
    return dummy.next


# Problem 8: Intersection of Two Linked Lists
# Find the intersection node of two linked lists
def get_intersection_node(headA, headB):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    if not headA or not headB:
        return None
    
    ptrA = headA
    ptrB = headB
    
    while ptrA != ptrB:
        ptrA = ptrA.next if ptrA else headB
        ptrB = ptrB.next if ptrB else headA
    
    return ptrA


# Problem 9: Palindrome Linked List
# Check if a linked list is a palindrome
def is_palindrome(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not head or not head.next:
        return True
    
    # Find middle
    slow = head
    fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    
    # Reverse second half
    second_half = reverse_linked_list(slow.next)
    first_half = head
    
    # Compare
    while second_half:
        if first_half.val != second_half.val:
            return False
        first_half = first_half.next
        second_half = second_half.next
    
    return True


# Problem 10: Add Two Numbers
# Add two numbers represented as linked lists (digits in reverse order)
def add_two_numbers(l1, l2):
    """
    Time Complexity: O(max(m, n))
    Space Complexity: O(max(m, n))
    """
    dummy = ListNode(0)
    current = dummy
    carry = 0
    
    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0
        
        total = val1 + val2 + carry
        carry = total // 10
        current.next = ListNode(total % 10)
        current = current.next
        
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    
    return dummy.next


# Problem 11: Reverse Nodes in k-Group
# Reverse nodes in groups of k
def reverse_k_group(head, k):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    def reverse_group(start, end):
        prev = end
        current = start
        while current != end:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev
    
    node = head
    for _ in range(k):
        if not node:
            return head
        node = node.next
    
    new_head = reverse_group(head, node)
    head.next = reverse_k_group(node, k)
    
    return new_head


# Problem 12: Swap Nodes in Pairs
# Swap every two adjacent nodes
def swap_pairs(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy
    
    while prev.next and prev.next.next:
        first = prev.next
        second = prev.next.next
        
        prev.next = second
        first.next = second.next
        second.next = first
        
        prev = first
    
    return dummy.next


# Problem 13: Remove Linked List Elements
# Remove all nodes with given value
def remove_elements(head, val):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    dummy = ListNode(0)
    dummy.next = head
    current = dummy
    
    while current.next:
        if current.next.val == val:
            current.next = current.next.next
        else:
            current = current.next
    
    return dummy.next


# Problem 14: Odd Even Linked List
# Group all odd nodes together followed by even nodes
def odd_even_list(head):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not head:
        return head
    
    odd = head
    even = head.next
    even_head = even
    
    while even and even.next:
        odd.next = even.next
        odd = odd.next
        even.next = odd.next
        even = even.next
    
    odd.next = even_head
    
    return head


# Problem 15: Delete Node in Linked List
# Delete a node (except tail) in O(1) time
def delete_node(node):
    """
    Time Complexity: O(1)
    Space Complexity: O(1)
    Note: Node is guaranteed not to be the tail
    """
    node.val = node.next.val
    node.next = node.next.next


# Test cases
if __name__ == "__main__":
    print("Problem 1 - Reverse Linked List:")
    head1 = create_linked_list([1, 2, 3, 4, 5])
    print("Original:", linked_list_to_array(head1))
    reversed_head = reverse_linked_list(head1)
    print("Reversed:", linked_list_to_array(reversed_head))
    
    print("\nProblem 2 - Merge Two Sorted Lists:")
    l1 = create_linked_list([1, 2, 4])
    l2 = create_linked_list([1, 3, 4])
    merged = merge_two_lists(l1, l2)
    print("Merged:", linked_list_to_array(merged))
    
    print("\nProblem 3 - Find Middle of Linked List:")
    head2 = create_linked_list([1, 2, 3, 4, 5])
    middle = middle_node(head2)
    print("Middle:", middle.val)
    
    print("\nProblem 4 - Remove Duplicates from Sorted List:")
    head3 = create_linked_list([1, 1, 2, 3, 3])
    no_duplicates = delete_duplicates(head3)
    print("After removing duplicates:", linked_list_to_array(no_duplicates))
    
    print("\nProblem 5 - Remove Nth Node From End:")
    head4 = create_linked_list([1, 2, 3, 4, 5])
    removed = remove_nth_from_end(head4, 2)
    print("After removing 2nd from end:", linked_list_to_array(removed))
    
    print("\nProblem 6 - Palindrome Linked List:")
    head5 = create_linked_list([1, 2, 2, 1])
    print("Is palindrome:", is_palindrome(head5))
    
    print("\nProblem 7 - Add Two Numbers:")
    num1 = create_linked_list([2, 4, 3])
    num2 = create_linked_list([5, 6, 4])
    sum_list = add_two_numbers(num1, num2)
    print("Sum:", linked_list_to_array(sum_list))
    
    print("\nProblem 8 - Swap Nodes in Pairs:")
    head6 = create_linked_list([1, 2, 3, 4])
    swapped = swap_pairs(head6)
    print("After swapping pairs:", linked_list_to_array(swapped))
    
    print("\nProblem 9 - Remove Linked List Elements:")
    head7 = create_linked_list([1, 2, 6, 3, 4, 5, 6])
    removed_val = remove_elements(head7, 6)
    print("After removing 6:", linked_list_to_array(removed_val))
    
    print("\nProblem 10 - Odd Even Linked List:")
    head8 = create_linked_list([1, 2, 3, 4, 5])
    odd_even = odd_even_list(head8)
    print("Odd even list:", linked_list_to_array(odd_even))
