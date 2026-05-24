/**
 * Basic DSA - Find the Prefix Common Array of Two Arrays (LeetCode 2657)
 * Track seen elements with a bitset-style count; common[i] grows as matching numbers appear in both prefixes.
 */
#include <iostream>
#include <vector>

std::vector<int> findThePrefixCommonArray(const std::vector<int>& A, const std::vector<int>& B) {
    int n = static_cast<int>(A.size());
    std::vector<int> seen(static_cast<size_t>(n) + 1, 0);
    std::vector<int> result(static_cast<size_t>(n), 0);
    int common = 0;
    for (int i = 0; i < n; ++i) {
        if (++seen[static_cast<size_t>(A[static_cast<size_t>(i)])] == 2)
            ++common;
        if (++seen[static_cast<size_t>(B[static_cast<size_t>(i)])] == 2)
            ++common;
        result[static_cast<size_t>(i)] = common;
    }
    return result;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Prefix Common Array of Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(findThePrefixCommonArray({1, 3, 2, 4}, {3, 1, 2, 4}));
    printVec(findThePrefixCommonArray({2, 3, 1}, {3, 1, 2}));
}
