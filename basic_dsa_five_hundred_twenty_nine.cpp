/**
 * Basic DSA - Remove Element (LeetCode 27)
 * Remove every occurrence of val from nums in place. Return k = new logical length;
 * the first k entries are the kept values in original relative order.
 * Time: O(n), Space: O(1) extra.
 */
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int w = 0;
    for (int x : nums) {
        if (x != val)
            nums[w++] = x;
    }
    return w;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {3, 2, 2, 3};
    int ka = removeElement(a, 3);
    std::cout << "val=3 k=" << ka << " prefix: ";
    for (int i = 0; i < ka; ++i)
        std::cout << a[i] << (i + 1 < ka ? "," : "");
    std::cout << "\n";

    std::vector<int> b = {0, 1, 2, 2, 3, 0, 4, 2};
    int kb = removeElement(b, 2);
    std::cout << "val=2 k=" << kb << " prefix: ";
    for (int i = 0; i < kb; ++i)
        std::cout << b[i] << (i + 1 < kb ? "," : "");
    std::cout << "\n";
}
