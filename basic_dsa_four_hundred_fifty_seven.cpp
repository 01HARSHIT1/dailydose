/**
 * Basic DSA - Sort Integers by The Number of 1 Bits (LeetCode 1356)
 * Ascending popcount; ties broken by ascending numeric value.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int popcount32(unsigned x) {
    return __builtin_popcount(x);
}

std::vector<int> sortByBits(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        int ca = popcount32(static_cast<unsigned>(a));
        int cb = popcount32(static_cast<unsigned>(b));
        if (ca != cb)
            return ca < cb;
        return a < b;
    });
    return arr;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort Integers by The Number of 1 Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    printVec(a1);
    std::cout << " -> ";
    printVec(sortByBits(a1));
    std::cout << "\n";

    std::vector<int> a2 = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    printVec(a2);
    std::cout << " -> ";
    printVec(sortByBits(a2));
    std::cout << "\n";
}
