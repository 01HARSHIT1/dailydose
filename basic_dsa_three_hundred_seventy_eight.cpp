/**
 * Basic DSA - Set Mismatch (LeetCode 645)
 * Permutation of 1..n with exactly one duplicate and one missing; find both.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> freq(n + 1);
    for (int x : nums)
        ++freq[x];
    int dup = -1, miss = -1;
    for (int i = 1; i <= n; ++i) {
        if (freq[i] == 2)
            dup = i;
        if (freq[i] == 0)
            miss = i;
    }
    return {dup, miss};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Set Mismatch\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 2, 4};
    auto r1 = findErrorNums(v1);
    std::cout << "[1,2,2,4] -> [" << r1[0] << "," << r1[1] << "]\n";

    std::vector<int> v2 = {3, 2, 2};
    auto r2 = findErrorNums(v2);
    std::cout << "[3,2,2] -> [" << r2[0] << "," << r2[1] << "]\n";
}
