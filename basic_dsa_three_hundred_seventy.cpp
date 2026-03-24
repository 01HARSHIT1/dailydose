/**
 * Basic DSA - Range Sum Query - Immutable (LeetCode 303)
 * Prefix sums for O(1) sumRange(left, right).
 */
#include <iostream>
#include <string>
#include <vector>

class NumArray {
    std::vector<int> pre;
public:
    NumArray(std::vector<int>& nums) {
        pre.resize(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); i++)
            pre[i + 1] = pre[i] + nums[i];
    }
    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Range Sum Query - Immutable\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray na(nums);
    std::cout << "sumRange(0,2) -> " << na.sumRange(0, 2) << "\n";
    std::cout << "sumRange(2,5) -> " << na.sumRange(2, 5) << "\n";
    std::cout << "sumRange(0,5) -> " << na.sumRange(0, 5) << "\n";
}
