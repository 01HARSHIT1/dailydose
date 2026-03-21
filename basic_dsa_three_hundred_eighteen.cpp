/**
 * Basic DSA - Odd Even Linked List (LeetCode 328)
 * Group odd-indexed nodes then even-indexed nodes (1-based).
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

void printList(ListNode* h) {
    while (h) {
        std::cout << h->val << (h->next ? "->" : "");
        h = h->next;
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Odd Even Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    printList(oddEvenList(a));

    ListNode* b = new ListNode(2);
    b->next = new ListNode(1);
    b->next->next = new ListNode(3);
    b->next->next->next = new ListNode(5);
    b->next->next->next->next = new ListNode(6);
    b->next->next->next->next->next = new ListNode(4);
    b->next->next->next->next->next->next = new ListNode(7);
    printList(oddEvenList(b));
}
