/**
 * Basic DSA - Remove Nth Node From End of List (LeetCode 19)
 * Remove the nth node from the end of a linked list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) { slow = slow->next; fast = fast->next; }
    slow->next = slow->next->next;
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        head = head->next;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Nth Node From End of List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    std::cout << "[1,2,3,4,5], n=2 -> ";
    printList(removeNthFromEnd(a, 2));
    std::cout << "\n";

    ListNode* b = new ListNode(1, new ListNode(2));
    std::cout << "[1,2], n=2 -> ";
    printList(removeNthFromEnd(b, 2));
    std::cout << "\n";
}
