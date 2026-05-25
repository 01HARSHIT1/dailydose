/**
 * Basic DSA - Divide Array Into Arrays With Max Difference (LeetCode 2966)
 * Sort, then group consecutive triplets; valid only if each triplet's span (max-min) is <= k.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> divideArray(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    for (size_t i = 0; i < nums.size(); i += 3) {
        if (nums[i + 2] - nums[i] > k)
            return {};
        result.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }
    return result;
}

void printResult(const std::vector<std::vector<int>>& groups) {
    if (groups.empty()) {
        std::cout << "[]\n";
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << "[" << groups[i][0] << "," << groups[i][1] << "," << groups[i][2] << "]";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Divide Array Into Arrays With Max Difference\n";
    std::cout << std::string(60, '=') << "\n";

    printResult(divideArray({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2));
    printResult(divideArray({2, 4, 2, 2, 5, 2}, 2));
}
