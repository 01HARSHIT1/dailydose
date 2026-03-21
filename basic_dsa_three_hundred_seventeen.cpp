/**
 * Basic DSA - Remove Nth Node From End of List (LeetCode 19)
 * Remove the nth node from the end of the list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
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
    std::cout << "Problem: Remove Nth Node From End of List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    printList(removeNthFromEnd(a, 2));

    ListNode* b = new ListNode(1);
    printList(removeNthFromEnd(b, 1));
}
