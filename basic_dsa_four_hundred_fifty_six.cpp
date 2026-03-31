/**
 * Basic DSA - Minimum Operations to Make the Array Increasing (LeetCode 1827)
 * Increment elements so nums becomes strictly increasing; minimize total increments.
 */
#include <iostream>
#include <vector>

int minOperations(std::vector<int>& nums) {
    long long ops = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i - 1]) {
            int bump = nums[i - 1] - nums[i] + 1;
            ops += bump;
            nums[i] += bump;
        }
    }
    return static_cast<int>(ops);
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Make the Array Increasing\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1, 1};
    printVec({1, 1, 1});
    std::cout << " -> " << minOperations(a1) << "\n";

    std::vector<int> a2 = {1, 5, 2, 4, 1};
    printVec({1, 5, 2, 4, 1});
    std::cout << " -> " << minOperations(a2) << "\n";

    std::vector<int> a3 = {8};
    printVec({8});
    std::cout << " -> " << minOperations(a3) << "\n";
}
