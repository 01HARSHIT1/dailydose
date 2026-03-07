/**
 * Basic DSA - Implement Trie (LeetCode 208)
 * Trie (prefix tree) with insert, search, and startsWith.
 */
#include <iostream>
#include <string>
#include <unordered_map>

class Trie {
    struct Node {
        std::unordered_map<char, Node*> child;
        bool end = false;
    };
    Node* root = new Node();
public:
    void insert(std::string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->child.count(c)) cur->child[c] = new Node();
            cur = cur->child[c];
        }
        cur->end = true;
    }
    bool search(std::string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->child.count(c)) return false;
            cur = cur->child[c];
        }
        return cur->end;
    }
    bool startsWith(std::string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->child.count(c)) return false;
            cur = cur->child[c];
        }
        return true;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement Trie\n";
    std::cout << std::string(60, '=') << "\n";

    Trie t;
    t.insert("apple");
    std::cout << "search(apple) -> " << (t.search("apple") ? "true" : "false") << "\n";
    std::cout << "search(app) -> " << (t.search("app") ? "true" : "false") << "\n";
    std::cout << "startsWith(app) -> " << (t.startsWith("app") ? "true" : "false") << "\n";
    t.insert("app");
    std::cout << "search(app) after insert -> " << (t.search("app") ? "true" : "false") << "\n";
}
