/**
 * Basic DSA - Remove Duplicates from Sorted Array (LeetCode 26)
 * Sorted non-decreasing nums. Overwrite so the first k entries are the unique values
 * in order; return k. Two pointers: slow holds next write, fast scans.
 * Time: O(n), Space: O(1) extra.
 */
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty())
        return 0;
    int w = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[w - 1])
            nums[w++] = nums[i];
    }
    return w;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Duplicates from Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 1, 2};
    int ka = removeDuplicates(a);
    std::cout << "k=" << ka << " prefix: ";
    for (int i = 0; i < ka; ++i)
        std::cout << a[i] << (i + 1 < ka ? "," : "");
    std::cout << "\n";

    std::vector<int> b = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int kb = removeDuplicates(b);
    std::cout << "k=" << kb << " prefix: ";
    for (int i = 0; i < kb; ++i)
        std::cout << b[i] << (i + 1 < kb ? "," : "");
    std::cout << "\n";

    std::vector<int> c = {42};
    int kc = removeDuplicates(c);
    std::cout << "k=" << kc << " prefix: ";
    for (int i = 0; i < kc; ++i)
        std::cout << c[i] << (i + 1 < kc ? "," : "");
    std::cout << "\n";
}
