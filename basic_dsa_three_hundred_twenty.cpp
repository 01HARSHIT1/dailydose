/**
 * Basic DSA - Design HashSet (LeetCode 705)
 * add, remove, contains for int keys.
 */
#include <iostream>
#include <vector>
#include <list>

class MyHashSet {
    static const int B = 1009;
    std::vector<std::list<int>> b;
    int h(int key) const { return key % B; }
public:
    MyHashSet() : b(B) {}
    void add(int key) {
        auto& chain = b[h(key)];
        for (int x : chain) if (x == key) return;
        chain.push_back(key);
    }
    void remove(int key) {
        auto& chain = b[h(key)];
        for (auto it = chain.begin(); it != chain.end(); ++it)
            if (*it == key) { chain.erase(it); return; }
    }
    bool contains(int key) {
        for (int x : b[h(key)]) if (x == key) return true;
        return false;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design HashSet\n";
    std::cout << std::string(60, '=') << "\n";

    MyHashSet s;
    s.add(1);
    s.add(2);
    std::cout << "contains(1) -> " << (s.contains(1) ? "true" : "false") << "\n";
    std::cout << "contains(3) -> " << (s.contains(3) ? "true" : "false") << "\n";
    s.add(2);
    std::cout << "contains(2) -> " << (s.contains(2) ? "true" : "false") << "\n";
    s.remove(2);
    std::cout << "contains(2) after remove -> " << (s.contains(2) ? "true" : "false") << "\n";
}
