/**
 * Basic DSA - Remove Linked List Elements (LeetCode 203)
 * Remove all nodes with value val.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* cur = &dummy;
    while (cur->next) {
        if (cur->next->val == val) cur->next = cur->next->next;
        else cur = cur->next;
    }
    return dummy.next;
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
    std::cout << "Problem: Remove Linked List Elements\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(6);
    a->next->next->next = new ListNode(3);
    a->next->next->next->next = new ListNode(4);
    a->next->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next->next = new ListNode(6);

    printList(removeElements(a, 6));

    ListNode* b = new ListNode(7);
    b->next = new ListNode(7);
    b->next->next = new ListNode(7);
    printList(removeElements(b, 7));
}
