/**
 * Basic DSA - Middle of the Linked List (LeetCode 876)
 * Return the middle node of a linked list (second middle if even length).
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Middle of the Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    std::cout << "[1,2,3,4,5] -> " << middleNode(a)->val << "\n";

    ListNode* b = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    std::cout << "[1,2,3,4,5,6] -> " << middleNode(b)->val << "\n";
}
