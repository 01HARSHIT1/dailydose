/**
 * Basic DSA - Intersection of Two Linked Lists (LeetCode 160)
 * Return node where lists intersect, or nullptr.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Linked Lists\n";
    std::cout << std::string(60, '=') << "\n";

    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* la = new ListNode(4);
    la->next = new ListNode(1);
    la->next->next = common;

    ListNode* lb = new ListNode(5);
    lb->next = new ListNode(6);
    lb->next->next = new ListNode(1);
    lb->next->next->next = common;

    ListNode* x = getIntersectionNode(la, lb);
    std::cout << "intersect at 8 -> " << (x ? x->val : -1) << "\n";

    ListNode* na = new ListNode(1);
    ListNode* nb = new ListNode(2);
    ListNode* y = getIntersectionNode(na, nb);
    std::cout << "no intersect -> " << (y ? y->val : -1) << "\n";
}
