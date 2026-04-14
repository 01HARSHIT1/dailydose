"""
Basic DSA - Merge Sorted Linked Lists
Merge two sorted singly linked lists and return the merged sorted list.
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def merge_two_lists(l1, l2):
    """
    Iterative merge with a dummy head.
    Time Complexity: O(m+n)
    Space Complexity: O(1) extra
    """
    dummy = ListNode(0)
    tail = dummy

    while l1 and l2:
        if l1.val <= l2.val:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next

    tail.next = l1 if l1 else l2
    return dummy.next


def from_list(values):
    dummy = ListNode(0)
    cur = dummy
    for v in values:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next


def to_list(head):
    out = []
    while head:
        out.append(head.val)
        head = head.next
    return out


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Sorted Linked Lists")
    print("=" * 60)

    tests = [
        ([1, 2, 4], [1, 3, 4], [1, 1, 2, 3, 4, 4]),
        ([], [], []),
        ([], [0], [0]),
        ([5, 6], [1, 2, 7], [1, 2, 5, 6, 7]),
    ]

    for a, b, expected in tests:
        got = to_list(merge_two_lists(from_list(a), from_list(b)))
        print(f"a={a}, b={b} -> {got} (expected {expected})")

