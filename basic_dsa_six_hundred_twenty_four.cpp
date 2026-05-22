/**
 * Basic DSA - Left and Right Sum Differences (LeetCode 2574)
 * answer[i] = |leftSum[i] - rightSum[i]|; track running prefix and suffix sums in one pass.
 */
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> leftRightDifference(const std::vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::vector<int> answer(nums.size());
    int leftSum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        int rightSum = total - leftSum - nums[i];
        answer[i] = std::abs(leftSum - rightSum);
        leftSum += nums[i];
    }
    return answer;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Left and Right Sum Differences\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(leftRightDifference({10, 4, 8, 3}));
    printVec(leftRightDifference({1}));
}
