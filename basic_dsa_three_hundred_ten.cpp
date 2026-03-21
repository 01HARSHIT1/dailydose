/**
 * Basic DSA - Reverse Linked List (LeetCode 206)
 * Reverse a singly linked list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
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
    std::cout << "Problem: Reverse Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);

    ListNode* r = reverseList(a);
    printList(r);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(2);
    printList(reverseList(b));
}
