/**
 * Basic DSA - Missing Number (LeetCode 268)
 * Find the only number missing from [0, n] in an array of n integers.
 */
#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    for (int x : nums) sum -= x;
    return sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Missing Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {3, 0, 1};
    std::cout << "[3,0,1] -> " << missingNumber(a1) << "\n";

    std::vector<int> a2 = {0, 1};
    std::cout << "[0,1] -> " << missingNumber(a2) << "\n";

    std::vector<int> a3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "[9,6,4,2,3,5,7,0,1] -> " << missingNumber(a3) << "\n";
}
