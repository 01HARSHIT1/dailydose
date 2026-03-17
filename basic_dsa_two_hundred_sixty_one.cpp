/**
 * Basic DSA - Max Consecutive Ones (LeetCode 485)
 * Return maximum number of consecutive 1's in binary array.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int cnt = 0, mx = 0;
    for (int x : nums) {
        cnt = x ? cnt + 1 : 0;
        mx = std::max(mx, cnt);
    }
    return mx;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Max Consecutive Ones\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 0, 1, 1, 1};
    std::cout << "[1,1,0,1,1,1] -> " << findMaxConsecutiveOnes(v1) << "\n";

    std::vector<int> v2 = {1, 0, 1, 1, 0, 1};
    std::cout << "[1,0,1,1,0,1] -> " << findMaxConsecutiveOnes(v2) << "\n";
}
