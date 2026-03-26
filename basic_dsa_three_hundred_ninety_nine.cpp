/**
 * Basic DSA - Sort Array By Parity II (LeetCode 922)
 * Even indices hold even integers; odd indices hold odd integers.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int e = 0;
    int o = 1;
    while (e < n && o < n) {
        if (nums[e] % 2 == 0) {
            e += 2;
        } else if (nums[o] % 2 == 1) {
            o += 2;
        } else {
            std::swap(nums[e], nums[o]);
        }
    }
    return nums;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort Array By Parity II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {4, 2, 5, 7};
    auto r1 = sortArrayByParityII(v1);
    std::cout << "[4,2,5,7] -> ";
    for (size_t i = 0; i < r1.size(); ++i)
        std::cout << (i ? "," : "") << r1[i];
    std::cout << "\n";

    std::vector<int> v2 = {2, 3};
    auto r2 = sortArrayByParityII(v2);
    std::cout << "[2,3] -> ";
    for (size_t i = 0; i < r2.size(); ++i)
        std::cout << (i ? "," : "") << r2[i];
    std::cout << "\n";
}
