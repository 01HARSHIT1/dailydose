/**
 * Basic DSA - Separate the Digits in an Array (LeetCode 2553)
 * Return all decimal digits of nums[0], then nums[1], ... in order.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> separateDigits(const std::vector<int>& nums) {
    std::vector<int> ans;
    for (int x : nums) {
        for (char c : std::to_string(x))
            ans.push_back(c - '0');
    }
    return ans;
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
    std::cout << "Problem: Separate the Digits in an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {13, 25, 2, 43};
    printVec(a1);
    std::cout << " -> ";
    printVec(separateDigits(a1));
    std::cout << "\n";

    std::vector<int> a2 = {7, 1, 3, 9};
    printVec(a2);
    std::cout << " -> ";
    printVec(separateDigits(a2));
    std::cout << "\n";
}
