/**
 * Basic DSA - Plus One (LeetCode 66)
 * Increment a non-negative integer given as most-significant-first digits by one.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            ++digits[i];
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
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
    std::cout << "Problem: Plus One\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> r1 = plusOne(a1);
    printVec({1, 2, 3});
    std::cout << " -> ";
    printVec(r1);
    std::cout << "\n";

    std::vector<int> a2 = {9};
    std::vector<int> r2 = plusOne(a2);
    printVec({9});
    std::cout << " -> ";
    printVec(r2);
    std::cout << "\n";

    std::vector<int> a3 = {9, 9, 9};
    std::vector<int> r3 = plusOne(a3);
    printVec({9, 9, 9});
    std::cout << " -> ";
    printVec(r3);
    std::cout << "\n";
}
