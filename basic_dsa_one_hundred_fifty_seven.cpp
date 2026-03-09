/**
 * Basic DSA - Reverse Linked List (LeetCode 206)
 * Reverse a singly linked list iteratively.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void printList(ListNode* head) {
    if (!head) { std::cout << "(empty)"; return; }
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        head = head->next;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    std::cout << "[1,2,3,4,5] -> ";
    printList(reverseList(a));
    std::cout << "\n";

    ListNode* b = new ListNode(1, new ListNode(2));
    std::cout << "[1,2] -> ";
    printList(reverseList(b));
    std::cout << "\n";

    std::cout << "[] -> ";
    printList(reverseList(nullptr));
    std::cout << "\n";
}
