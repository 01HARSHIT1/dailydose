/**
 * Basic DSA - Jump Game (LeetCode 55)
 * Return true if last index reachable from 0 with jumps nums[i].
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > reach) return false;
        reach = std::max(reach, i + nums[i]);
        if (reach >= (int)nums.size() - 1) return true;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Jump Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 3, 1, 1, 4};
    std::cout << "[2,3,1,1,4] -> " << (canJump(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {3, 2, 1, 0, 4};
    std::cout << "[3,2,1,0,4] -> " << (canJump(v2) ? "true" : "false") << "\n";
}
