/**
 * Basic DSA - Running Sum of 1d Array (LeetCode 1480)
 * Return running sum: output[i] = sum(nums[0]..nums[i]).
 */
#include <iostream>
#include <vector>

std::vector<int> runningSum(std::vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); i++)
        nums[i] += nums[i - 1];
    return nums;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Running Sum of 1d Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4};
    auto r1 = runningSum(a1);
    std::cout << "[1,2,3,4] -> ";
    print(r1);

    std::vector<int> a2 = {1, 1, 1, 1, 1};
    auto r2 = runningSum(a2);
    std::cout << "[1,1,1,1,1] -> ";
    print(r2);

    std::vector<int> a3 = {3, 1, 2, 10, 1};
    auto r3 = runningSum(a3);
    std::cout << "[3,1,2,10,1] -> ";
    print(r3);
}
