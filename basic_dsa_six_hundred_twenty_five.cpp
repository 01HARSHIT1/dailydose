/**
 * Basic DSA - Find the Divisibility Array of a String (LeetCode 2575)
 * Build the number digit by digit modulo m; mark 1 when the running remainder hits 0.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> divisibilityArray(const std::string& word, int m) {
    std::vector<int> result(word.size());
    long long remainder = 0;
    for (size_t i = 0; i < word.size(); ++i) {
        remainder = (remainder * 10 + (word[i] - '0')) % m;
        result[i] = (remainder == 0) ? 1 : 0;
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
    std::cout << "Problem: Find the Divisibility Array of a String\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(divisibilityArray("998244353", 3));
    printVec(divisibilityArray("1010", 10));
}
