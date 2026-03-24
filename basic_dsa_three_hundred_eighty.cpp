/**
 * Basic DSA - Non-decreasing Array (LeetCode 665)
 * Whether the array can become non-decreasing by changing at most one element.
 */
#include <iostream>
#include <string>
#include <vector>

bool checkPossibility(std::vector<int>& nums) {
    int modified = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            if (++modified > 1)
                return false;
            if (i >= 2 && nums[i] < nums[i - 2])
                nums[i] = nums[i - 1];
            else
                nums[i - 1] = nums[i];
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Non-decreasing Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {4, 2, 3};
    std::cout << "[4,2,3] -> " << (checkPossibility(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {3, 4, 2, 3};
    std::cout << "[3,4,2,3] -> " << (checkPossibility(v2) ? "true" : "false") << "\n";
}
