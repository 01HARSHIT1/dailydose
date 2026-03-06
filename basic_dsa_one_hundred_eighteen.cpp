/**
 * Basic DSA - Linked List Cycle (LeetCode 141)
 * Detect if linked list has a cycle (Floyd's cycle detection).
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Linked List Cycle\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(3);
    a->next = new ListNode(2);
    a->next->next = new ListNode(0);
    a->next->next->next = new ListNode(-4);
    a->next->next->next->next = a->next;  // cycle to index 1
    std::cout << "[3,2,0,-4] with cycle -> " << (hasCycle(a) ? "true" : "false") << "\n";

    ListNode* b = new ListNode(1);
    b->next = new ListNode(2);
    b->next->next = b;  // cycle
    std::cout << "[1,2] with cycle -> " << (hasCycle(b) ? "true" : "false") << "\n";

    ListNode* c = new ListNode(1);
    std::cout << "[1] no cycle -> " << (hasCycle(c) ? "true" : "false") << "\n";
}
