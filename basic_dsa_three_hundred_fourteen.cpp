/**
 * Basic DSA - Middle of the Linked List (LeetCode 876)
 * Return the middle node; if two middles, return the second.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printFrom(ListNode* h) {
    while (h) {
        std::cout << h->val << (h->next ? "->" : "");
        h = h->next;
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Middle of the Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    printFrom(middleNode(a));

    ListNode* b = new ListNode(1);
    b->next = new ListNode(2);
    b->next->next = new ListNode(3);
    b->next->next->next = new ListNode(4);
    b->next->next->next->next = new ListNode(5);
    b->next->next->next->next->next = new ListNode(6);
    printFrom(middleNode(b));
}
