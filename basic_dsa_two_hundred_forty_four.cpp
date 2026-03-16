/**
 * Basic DSA - Two Sum II - Input Array Is Sorted (LeetCode 167)
 * Find two indices (1-based) such that numbers add to target.
 */
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int lo = 0, hi = numbers.size() - 1;
    while (lo < hi) {
        int sum = numbers[lo] + numbers[hi];
        if (sum == target) return {lo + 1, hi + 1};
        if (sum < target) lo++;
        else hi--;
    }
    return {};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum II - Input Array Is Sorted\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 7, 11, 15};
    auto r1 = twoSum(v1, 9);
    std::cout << "[2,7,11,15], 9 -> [" << r1[0] << "," << r1[1] << "]\n";

    std::vector<int> v2 = {2, 3, 4};
    auto r2 = twoSum(v2, 6);
    std::cout << "[2,3,4], 6 -> [" << r2[0] << "," << r2[1] << "]\n";

    std::vector<int> v3 = {-1, 0};
    auto r3 = twoSum(v3, -1);
    std::cout << "[-1,0], -1 -> [" << r3[0] << "," << r3[1] << "]\n";
}
