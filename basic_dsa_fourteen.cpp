/**
 * Basic DSA - Rotate Array (LeetCode 189)
 * Rotate array to the right by k steps in-place.
 */
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = (int)nums.size();
    k %= n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Rotate Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    rotate(a1, 3);
    std::cout << "[1,2,3,4,5,6,7], k=3 -> ";
    print(a1);

    std::vector<int> a2 = {-1, -100, 3, 99};
    rotate(a2, 2);
    std::cout << "[-1,-100,3,99], k=2 -> ";
    print(a2);
}
