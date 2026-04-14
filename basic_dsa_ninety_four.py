"""
Basic DSA - Detect Cycle in Linked List
Return True if a linked list has a cycle, otherwise False.
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def has_cycle(head):
    """
    Floyd's tortoise and hare.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            return True
    return False


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Detect Cycle in Linked List")
    print("=" * 60)

    # 3 -> 2 -> 0 -> -4 -> (back to 2)
    a = ListNode(3)
    b = ListNode(2)
    c = ListNode(0)
    d = ListNode(-4)
    a.next = b
    b.next = c
    c.next = d
    d.next = b
    print(has_cycle(a))  # True

    # 1 -> 2 -> None
    x = ListNode(1, ListNode(2))
    print(has_cycle(x))  # False

