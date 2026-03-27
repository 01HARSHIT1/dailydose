/**
 * Basic DSA - Binary Prefix Divisible By 5 (LeetCode 1018)
 * bits[i] extend the number left to right; after each bit, is the value divisible by 5?
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<bool> prefixesDivBy5(const std::vector<int>& bits) {
    std::vector<bool> ans;
    int val = 0;
    for (int b : bits) {
        val = (val * 2 + b) % 5;
        ans.push_back(val == 0);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Prefix Divisible By 5\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {0, 1, 1};
    auto a1 = prefixesDivBy5(v1);
    std::cout << "[0,1,1] -> ";
    for (size_t i = 0; i < a1.size(); ++i)
        std::cout << (i ? "," : "") << (a1[i] ? "true" : "false");
    std::cout << "\n";

    std::vector<int> v2 = {1, 0, 1};
    auto a2 = prefixesDivBy5(v2);
    std::cout << "[1,0,1] -> ";
    for (size_t i = 0; i < a2.size(); ++i)
        std::cout << (i ? "," : "") << (a2[i] ? "true" : "false");
    std::cout << "\n";
}
