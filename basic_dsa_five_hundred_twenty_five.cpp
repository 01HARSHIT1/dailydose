/**
 * Basic DSA - Plus One (LeetCode 66)
 * digits[0] is the most significant digit; add one to the number with no leading zero
 * (except the single digit 0). Propagate carry from the right; if all were 9, prepend 1.
 * Time: O(n), Space: O(1) extra aside from output growth by at most one cell.
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
            std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Plus One\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(plusOne({1, 2, 3}));
    printVec(plusOne({4, 3, 2, 1}));
    printVec(plusOne({9}));
    printVec(plusOne({9, 9}));
}
