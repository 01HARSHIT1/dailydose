/**
 * Basic DSA - Find the Score of All Prefixes of an Array (LeetCode 2640)
 * conver[i] = nums[i] + max so far; answer is the running prefix sum of conver values.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<long long> findPrefixScore(const std::vector<int>& nums) {
    std::vector<long long> answer(nums.size());
    long long maxSoFar = 0;
    long long runningSum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        maxSoFar = std::max(maxSoFar, static_cast<long long>(nums[i]));
        long long conver = nums[i] + maxSoFar;
        runningSum += conver;
        answer[i] = runningSum;
    }
    return answer;
}

void printVec(const std::vector<long long>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Score of All Prefixes of an Array\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(findPrefixScore({2, 3, 7, 5, 10}));
    printVec(findPrefixScore({1, 1, 2, 4, 8, 16}));
}
