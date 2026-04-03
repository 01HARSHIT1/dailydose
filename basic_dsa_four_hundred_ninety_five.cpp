/**
 * Basic DSA - Remove Element (LeetCode 27)
 * Remove all occurrences of val in-place; return new length k (first k entries are valid).
 */
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0;
    for (int x : nums) {
        if (x != val)
            nums[k++] = x;
    }
    return k;
}

void printVec(const std::vector<int>& v, int len) {
    std::cout << "[";
    for (int i = 0; i < len; ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {3, 2, 2, 3};
    int k1 = removeElement(a, 3);
    std::cout << "nums=[3,2,2,3], val=3 -> k=" << k1 << ", ";
    printVec(a, k1);
    std::cout << "\n";

    std::vector<int> b = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = removeElement(b, 2);
    std::cout << "nums=[0,1,2,2,3,0,4,2], val=2 -> k=" << k2 << ", ";
    printVec(b, k2);
    std::cout << "\n";
}
