/**
 * Basic DSA - Design Linked List (LeetCode 707)
 * Singly linked list: get, addAtHead, addAtTail, addAtIndex, deleteAtIndex.
 */
#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class MyLinkedList {
    Node* head;
    int len;
public:
    MyLinkedList() : head(nullptr), len(0) {}
    int get(int index) {
        if (index < 0 || index >= len) return -1;
        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->val;
    }
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        len++;
    }
    void addAtTail(int val) {
        if (!head) { addAtHead(val); return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(val);
        len++;
    }
    void addAtIndex(int index, int val) {
        if (index > len) return;
        if (index <= 0) { addAtHead(val); return; }
        if (index == len) { addAtTail(val); return; }
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node* n = new Node(val);
        n->next = cur->next;
        cur->next = n;
        len++;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;
        if (index == 0) {
            Node* t = head;
            head = head->next;
            delete t;
            len--;
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node* t = cur->next;
        cur->next = t->next;
        delete t;
        len--;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Linked List\n";
    std::cout << std::string(60, '=') << "\n";

    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    std::cout << "get(1) -> " << list.get(1) << "\n";
    list.deleteAtIndex(1);
    std::cout << "get(1) after delete -> " << list.get(1) << "\n";
}
