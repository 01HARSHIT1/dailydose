/**
 * Basic DSA - Design HashMap (LeetCode 706)
 * put, get, remove with int keys and values.
 */
#include <iostream>
#include <vector>
#include <list>

class MyHashMap {
    static const int B = 1009;
    std::vector<std::list<std::pair<int, int>>> b;
    int h(int key) const { return key % B; }
public:
    MyHashMap() : b(B) {}
    void put(int key, int value) {
        auto& chain = b[h(key)];
        for (auto& p : chain)
            if (p.first == key) { p.second = value; return; }
        chain.push_back({key, value});
    }
    int get(int key) {
        for (auto& p : b[h(key)])
            if (p.first == key) return p.second;
        return -1;
    }
    void remove(int key) {
        auto& chain = b[h(key)];
        for (auto it = chain.begin(); it != chain.end(); ++it)
            if (it->first == key) { chain.erase(it); return; }
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design HashMap\n";
    std::cout << std::string(60, '=') << "\n";

    MyHashMap m;
    m.put(1, 1);
    m.put(2, 2);
    std::cout << "get(1) -> " << m.get(1) << "\n";
    std::cout << "get(3) -> " << m.get(3) << "\n";
    m.put(2, 1);
    std::cout << "get(2) after put -> " << m.get(2) << "\n";
    m.remove(2);
    std::cout << "get(2) after remove -> " << m.get(2) << "\n";
}
