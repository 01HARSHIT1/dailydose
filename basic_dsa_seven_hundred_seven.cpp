/**
 * Basic DSA - Minimum Cost to Make Arrays Identical (LeetCode 3424)
 * Either match in place or pay k to sort arr and align with sorted brr.
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

long long pairCost(const std::vector<int>& a, const std::vector<int>& b) {
    long long total = 0;
    for (size_t i = 0; i < a.size(); ++i)
        total += std::llabs(static_cast<long long>(a[i]) - b[i]);
    return total;
}

long long minCost(std::vector<int> arr, std::vector<int> brr, long long k) {
    long long withoutSort = pairCost(arr, brr);
    std::sort(arr.begin(), arr.end());
    std::sort(brr.begin(), brr.end());
    long long withSort = pairCost(arr, brr) + k;
    return std::min(withoutSort, withSort);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Cost to Make Arrays Identical\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minCost({-7, 9, 5}, {7, -2, -5}, 2) << "\n";
    std::cout << "sample 2 -> " << minCost({2, 1}, {2, 1}, 0) << "\n";
}
