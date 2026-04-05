/**
 * Basic DSA - Rotate Array (LeetCode 189)
 * Rotate nums to the right by k steps in-place. Use reverse whole array, then
 * reverse first k and the rest (k taken mod n).
 * Time: O(n), Space: O(1) extra.
 */
#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    if (n == 0)
        return;
    k %= n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
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
    std::cout << "Problem: Rotate Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    printVec(a);

    std::vector<int> b = {-1, -100, 3, 99};
    rotate(b, 2);
    printVec(b);

    std::vector<int> c = {1, 2};
    rotate(c, 5);
    printVec(c);
}
