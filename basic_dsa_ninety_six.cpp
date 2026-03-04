/**
 * Basic DSA - Decode XORed Array (LeetCode 1720)
 * Recover original array from encoded where encoded[i] = arr[i] XOR arr[i+1].
 */
#include <iostream>
#include <vector>

std::vector<int> decode(std::vector<int>& encoded, int first) {
    std::vector<int> out = {first};
    for (int x : encoded) {
        out.push_back(out.back() ^ x);
    }
    return out;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Decode XORed Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> e1 = {1, 2, 3};
    auto r1 = decode(e1, 1);
    std::cout << "encoded=[1,2,3], first=1 -> ";
    print(r1);

    std::vector<int> e2 = {6, 2, 7, 3};
    auto r2 = decode(e2, 4);
    std::cout << "encoded=[6,2,7,3], first=4 -> ";
    print(r2);
}
