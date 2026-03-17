/**
 * Basic DSA - Minimum Value to Get Positive Step by Step Sum (LeetCode 1413)
 * Return minimum startValue so step-by-step sum never drops below 1.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int minStartValue(std::vector<int>& nums) {
    int sum = 0, mn = 0;
    for (int x : nums) {
        sum += x;
        mn = std::min(mn, sum);
    }
    return 1 - mn;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Value to Get Positive Step by Step Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-3, 2, -3, 4, 2};
    std::cout << "[-3,2,-3,4,2] -> " << minStartValue(v1) << "\n";

    std::vector<int> v2 = {1, 2};
    std::cout << "[1,2] -> " << minStartValue(v2) << "\n";

    std::vector<int> v3 = {1, -2, -3};
    std::cout << "[1,-2,-3] -> " << minStartValue(v3) << "\n";
}
