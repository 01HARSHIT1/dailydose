/**
 * Basic DSA - Running Sum of 1d Array (LeetCode 1480)
 * runningSum[i] = nums[0] + ... + nums[i].
 */
#include <iostream>
#include <vector>

std::vector<int> runningSum(const std::vector<int>& nums) {
    std::vector<int> out(nums.size());
    if (nums.empty())
        return out;
    out[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
        out[i] = out[i - 1] + nums[i];
    return out;
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
    std::cout << "Problem: Running Sum of 1d Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4};
    printVec(a1);
    std::cout << " -> ";
    printVec(runningSum(a1));
    std::cout << "\n";

    std::vector<int> a2 = {1, 1, 1, 1, 1};
    printVec(a2);
    std::cout << " -> ";
    printVec(runningSum(a2));
    std::cout << "\n";
}
