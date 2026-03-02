/**
 * Basic DSA - Jump Game (LeetCode 55)
 * Check if you can reach the last index (nums[i] = max jump from i).
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i < (int)nums.size() && i <= reach; i++) {
        reach = std::max(reach, i + nums[i]);
        if (reach >= (int)nums.size() - 1) return true;
    }
    return reach >= (int)nums.size() - 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Jump Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 3, 1, 1, 4};
    std::cout << "[2,3,1,1,4] -> " << (canJump(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {3, 2, 1, 0, 4};
    std::cout << "[3,2,1,0,4] -> " << (canJump(a2) ? "true" : "false") << "\n";

    std::vector<int> a3 = {0};
    std::cout << "[0] -> " << (canJump(a3) ? "true" : "false") << "\n";
}
