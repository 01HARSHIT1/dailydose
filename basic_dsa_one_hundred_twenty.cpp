/**
 * Basic DSA - Reorder List (LeetCode 143)
 * L0 -> Ln -> L1 -> Ln-1 -> ... (reorder in-place).
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;

    ListNode* prev = nullptr;
    while (second) {
        ListNode* nxt = second->next;
        second->next = prev;
        prev = second;
        second = nxt;
    }

    ListNode* p1 = head, *p2 = prev;
    while (p2) {
        ListNode* n1 = p1->next, *n2 = p2->next;
        p1->next = p2;
        p2->next = n1;
        p1 = n1;
        p2 = n2;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reorder List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);

    reorderList(a);
    std::cout << "[1,2,3,4] reordered -> ";
    while (a) { std::cout << a->val << (a->next ? "," : ""); a = a->next; }
    std::cout << "\n";
}
