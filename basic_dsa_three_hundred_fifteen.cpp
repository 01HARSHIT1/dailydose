/**
 * Basic DSA - Palindrome Linked List (LeetCode 234)
 * Return true if values read forward equal backward.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = reverse(slow->next);
    slow->next = nullptr;
    ListNode* p1 = head, *p2 = second;
    bool ok = true;
    while (p2) {
        if (p1->val != p2->val) ok = false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return ok;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Palindrome Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(2);
    a->next->next->next = new ListNode(1);
    std::cout << "[1,2,2,1] -> " << (isPalindrome(a) ? "true" : "false") << "\n";

    ListNode* b = new ListNode(1);
    b->next = new ListNode(2);
    std::cout << "[1,2] -> " << (isPalindrome(b) ? "true" : "false") << "\n";
}
