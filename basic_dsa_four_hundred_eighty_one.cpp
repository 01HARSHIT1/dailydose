/**
 * Basic DSA - Plus One (LeetCode 66)
 * Digits represent a non-negative integer (MSB first). Add one and return digits.
 */
#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> digits) {
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
    printVec(a1);
    std::cout << " -> ";
    printVec(plusOne(a1));
    std::cout << "\n";

    std::vector<int> a2 = {9, 9};
    printVec(a2);
    std::cout << " -> ";
    printVec(plusOne(a2));
    std::cout << "\n";
}
