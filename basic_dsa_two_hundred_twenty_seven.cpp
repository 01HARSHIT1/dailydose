/**
 * Basic DSA - Find the Duplicate Number (LeetCode 287)
 * Find duplicate in array of n+1 integers in range [1,n] (Floyd cycle detection).
 */
#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Duplicate Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 3, 4, 2, 2};
    std::cout << "[1,3,4,2,2] -> " << findDuplicate(a1) << "\n";

    std::vector<int> a2 = {3, 1, 3, 4, 2};
    std::cout << "[3,1,3,4,2] -> " << findDuplicate(a2) << "\n";
}
