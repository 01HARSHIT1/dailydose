/**
 * Basic DSA - Majority Element II (LeetCode 229)
 * Find all elements that appear more than n/3 times (Boyer-Moore variant).
 */
#include <iostream>
#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums) {
    int c1 = 0, c2 = 0, v1 = 0, v2 = 0;
    for (int x : nums) {
        if (x == v1) c1++;
        else if (x == v2) c2++;
        else if (c1 == 0) { v1 = x; c1 = 1; }
        else if (c2 == 0) { v2 = x; c2 = 1; }
        else { c1--; c2--; }
    }
    c1 = c2 = 0;
    for (int x : nums) {
        if (x == v1) c1++;
        else if (x == v2) c2++;
    }
    std::vector<int> out;
    int n = nums.size();
    if (c1 > n / 3) out.push_back(v1);
    if (c2 > n / 3) out.push_back(v2);
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Majority Element II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {3, 2, 3};
    auto r1 = majorityElement(a1);
    std::cout << "[3,2,3] -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {1, 1, 1, 3, 3, 2, 2, 2};
    auto r2 = majorityElement(a2);
    std::cout << "[1,1,1,3,3,2,2,2] -> [";
    for (size_t i = 0; i < r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
