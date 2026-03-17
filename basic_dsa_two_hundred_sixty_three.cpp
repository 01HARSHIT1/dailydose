/**
 * Basic DSA - Running Sum of 1d Array (LeetCode 1480)
 * Return running sum: nums[i] = sum(nums[0]..nums[i]).
 */
#include <iostream>
#include <vector>

std::vector<int> runningSum(std::vector<int>& nums) {
    for (int i = 1; i < (int)nums.size(); i++)
        nums[i] += nums[i - 1];
    return nums;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Running Sum of 1d Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 3, 4};
    runningSum(v1);
    std::cout << "[1,2,3,4] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {1, 1, 1, 1, 1};
    runningSum(v2);
    std::cout << "[1,1,1,1,1] -> [";
    for (int i = 0; i < (int)v2.size(); i++) std::cout << (i ? "," : "") << v2[i];
    std::cout << "]\n";
}
