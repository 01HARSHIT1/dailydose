/**
 * Basic DSA - Merge Two Sorted Lists (LeetCode 21)
 * Merge two sorted linked lists into one sorted list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Two Sorted Lists\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* m = mergeTwoLists(a, b);
    std::cout << "[1,2,4] + [1,3,4] -> ";
    while (m) {
        std::cout << m->val << (m->next ? "," : "");
        m = m->next;
    }
    std::cout << "\n";
}
